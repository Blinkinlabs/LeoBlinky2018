#include <ch554.h>
#include <debug.h>
#include <string.h>
#include <bootloader.h>

#include "uart0_int.h"
#include "uart1_int.h"

#include "leoblinky2018.h"
#include "icn2053.h"
#include "comms.h"
#include "patterns.h"
#include "spi.h"
#include "spi_flash.h"

#include "uart.h"
#include "usb_cdc.h"
#include "usb_protocol.h"

void sendByte(uint8_t byte) {
    Receive_Uart_Buf[Uart_Input_Point++] = byte;
    UartByteCount++;                    //Current buffer remaining bytes to be fetched
    if(Uart_Input_Point>=UART_REV_LEN)
        Uart_Input_Point = 0;           //Write pointer
}

// Handle full messages here
void parsePayload() { //uint16_t dataSize, uint8_t* data) {
    uint32_t address;
    uint8_t i;

    switch(usb_protocol_payloadData[0]) {
        case 0x00:  // Display some data on the LEDs
        {
            if(usb_protocol_payloadLength < 1 + LED_COUNT)
                return;
            for(i = 0; i < LED_COUNT; i++)
                ledData[streamToPhysical[i]] = usb_protocol_payloadData[i+1];

            frameReady = true;
        }
        case 0x01:  // Clear the flash
        {
            if(usb_protocol_payloadLength != 1) {
                return;
            }
            Flash_EraseChip();

            // send an OK to the pc
            sendByte('!');
        }
            break;

//        case 0x02:  // Program a page of memory
//        {
//            if(usb_protocol_payloadLength != (1 + 4 + 256)) {
//                return;
//            }

//            address =
//                  (data[1] << 24)
//                + (data[2] << 16)
//                + (data[3] <<  8)
//                + (data[4]      );

//            flash.setWriteEnable(true);
//            flash.writePage(address, (uint8_t*) &data[5]);
//            while(flash.busy()) {
//                delay(10);
//                watchdog_refresh();
//            }
//            flash.setWriteEnable(false);

//            // send an OK to the pc
//            sendByte('!');
//        }
//            break;
//        case 0x03:  // Reload animations
//        {
//            reloadAnimations = true;

//            // send an OK to the pc
//            sendByte('!');
//        }
//            break;

        default:
            break;
    }
}

void initBoard() {
    CfgFsys();

    //UART0Setup();
    mInitSTDIO();
    UART1Setup();
    CH554UART1Alter();

    UART0_buf_init();
    UART1_buf_init();

    USBDeviceCfg();
    USBDeviceEndPointCfg();                                               //Endpoint configuration
    USBDeviceIntCfg();                                                    //Interrupt initialization
    UEP0_T_LEN = 0;
    UEP1_T_LEN = 0;                                                       //Pre-use send length must be cleared
    UEP2_T_LEN = 0;                                                       //Pre-use send length must be cleared

    usb_protocol_reset();

    SPIMasterModeSet(0);    // Configure SPI for master mode operation
    Flash_ReadJEDECID();

    // Configure Timer2 for GCLK generation at 4MHz
    RCLK = 0;
    TCLK = 0;

    T2MOD |= bTMR_CLK | bT2_CLK | T2OE;
    RCAP2L = 254;
    RCAP2H = 255;
    TL2 = 254;
    TH2 = 255;

    // Configure Timer0 for a system tick counter at ?Hz
    // Used to:
    // - set framerate (need resolution of ~1us)
    // - reset UART error conditions (need resolution of ~3us)
    // - send geometry updates (preferably at 1s intervals)
//    TMOD = TMOD & ~bT1_GATE & ~bT0_CT & ~MASK_T0_MOD | bT0_M0;

    //TMOD &= ~bT0_GATE & ~bT0_CT & ~MASK_T0_MOD;
    TMOD |= bT0_M0;
    T2MOD |= bTMR_CLK | bT0_CLK;
    TF0 = 0;
    TR0 = 1;


    // Configure output pins on port 
    P1_DIR_PU = 0x0F;   // TODO: Do we need to enable pullups?
    P1_MOD_OC = P1_MOD_OC
                & ~(1<<LED_CLK_PIN)
                & ~(1<<LED_MOSI_PIN)
                & ~(1<<LED_LE_PIN)
                & ~(1<<LED_GCLK_PIN);
    P1_DIR_PU = P1_DIR_PU
                | (1<<LED_CLK_PIN)
                | (1<<LED_MOSI_PIN)
                | (1<<LED_LE_PIN)
                | (1<<LED_GCLK_PIN);


    LED_CLK = 0;
    LED_MOSI = 0;
    LED_LE = 0;


    // Note: inputs on port3 do not need to be initialized, since
    // they are set correctly be default.

    icn2053_begin();

    ledsToLeft = 0;
    lettersToLeft = 0;
    ttlLeft = 0;

    ledsToRight = 0;
    lettersToRight = 0;
    ttlRight = 0;

    brightness = 255;

    pattern = 0;
    frame = 0;

    frameReady = false;

    icn2053_setBrightness(brightness);

    CH554WDTModeSelect(1);
}

void main() {
    bool streamingMode = false;

    uint8_t geometryUpdateTimer = 0;
    uint8_t outputTimer = 0;

    uint8_t Uart_Timeout = 0;
//    uint8_t length;

    bool button1State = 1;
    bool button2State = 1;

    initBoard();

    // If both buttons are held down, jump to bootloader mode
    if((BUTTON1 == 0) && (BUTTON2 == 0)) {
        EA = 0;
        CH554WDTModeSelect(0);
        bootloader();
    }

    while (1) {

/// Check buttons
        if((BUTTON1 == 0) && (button1State == 1)) {
            pattern++;
            if(pattern == PATTERN_COUNT)
                pattern = 0;
        }
        button1State = BUTTON1;
       
        if((BUTTON2 == 0) && (button2State == 1)) {
            brightness /= 2;
            if(brightness < 1)
                brightness = 255;
            brightnessChanged = true;
        }
        button2State = BUTTON2;

// Check UARTS
        receiveLeft();
        receiveRight();

// Check USB
        if(UsbConfig)
        {
            if(USBByteCount)   // USB receiving endpoint has data
            {
                streamingMode = true;

                usb_protocol_parseByte(Ep2Buffer[USBBufOutPoint++]);
                USBByteCount--;
                if(USBByteCount==0)
                    UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_R_RES | UEP_R_RES_ACK;

                // If we've gotten a full frame of data, display it
                if(usb_protocol_payloadReady()) {
                    parsePayload();
                    usb_protocol_reset();
                }
            }
            if(UartByteCount)
                Uart_Timeout++;
//            if(!UpPoint2_Busy)   //The endpoint is not busy (the first packet of data after idle, only used to trigger upload）
//            {
//                length = UartByteCount;
//                if(length>0)
//                {
//                    if(length>39 || Uart_Timeout>100)
//                    {
//                        Uart_Timeout = 0;
//                        if(Uart_Output_Point+length>UART_REV_LEN)
//                            length = UART_REV_LEN-Uart_Output_Point;
//                        UartByteCount -= length;
//                        //Write upload endpoint
//                        memcpy(Ep2Buffer+MAX_PACKET_SIZE,&Receive_Uart_Buf[Uart_Output_Point],length);
//                        Uart_Output_Point+=length;
//                        if(Uart_Output_Point>=UART_REV_LEN)
//                            Uart_Output_Point = 0;
//                        UEP2_T_LEN = length;                                        //Pre-use send length must be cleared
//                        UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;   //Answer ACK
//                        UpPoint2_Busy = 1;
//                    }
//                }
//            }
        }


// Handle system changes
        if(brightnessChanged) {
            brightnessChanged = false;
            icn2053_setBrightness(brightness);
        }

        if(frameReady) {
            frameReady = false;

            if(!streamingMode) {
                sendUpdateRight();

                if(pattern == 0)
                    marchingLetters();
                else if(pattern == 1)
                    marchingLeds();
            }

            icn2053_updateDisplay(ledData);
        }

// count ticks. Using a 16MHz / 1 / 2^16 input, we get a tick
// every 4.096mS.
        if(TF0) {
            TF0 = 0;

            CH554WDTFeed(WDOG_FEED_TIME);

            // ticks = ~244/fps
            // 8 ticks = ~30fps
            // 4 ticks = ~60fps
            outputTimer++;
            if((ledsToLeft == 0) && (outputTimer > 3) && !streamingMode) {
                outputTimer = 0;

                frame += 1;
                frameReady = true;
            }

            // 244 ticks ~= 1 second
            // 122 ticks ~= .5 seconds
            geometryUpdateTimer++;
            if(geometryUpdateTimer > 122) {
                geometryUpdateTimer = 0;

                sendGeometryLeft();
                sendGeometryRight();

                if(ttlLeft > 0) {
                    ttlLeft--;
                    if(ttlLeft == 0) {
                        ledsToLeft = 0;
                        lettersToLeft = 0;
                    }
                }
                if(ttlRight > 0) {
                    ttlRight--;
                    if(ttlRight == 0) {
                        ledsToRight = 0;
                        lettersToRight = 0;
                    }
                }
            }
        }
    }
}
