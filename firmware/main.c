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
#include "animations.h"

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

        case 0x02:  // Program a page of memory
        {
            if(usb_protocol_payloadLength != (1 + 4 + FLASH_PAGESIZE)) {
                return;
            }

            address = usb_protocol_payloadData[1];
            address = address << 8;
            address |= usb_protocol_payloadData[2];
            address = address << 8;
            address |= usb_protocol_payloadData[3];
            address = address << 8;
            address |= usb_protocol_payloadData[4];

            Flash_Write(address,
                        FLASH_PAGESIZE,
                        &usb_protocol_payloadData[5]);

            // send an OK to the pc
            sendByte('!');
        }
            break;

        case 0x03:  // Reload animations
        {
            animations_initialize();

            // send an OK to the pc
            sendByte('!');
        }
            break;

        default:
            break;
    }
}

void initBoard() {
    CfgFsys();

    // If both buttons are held down, jump to bootloader mode
    if((BUTTON1 == 0) && (BUTTON2 == 0)) {
        EA = 0;
        CH554WDTModeSelect(0);
        bootloader();
    }

    CH554WDTModeSelect(1);  // Init watchdog

    mInitSTDIO();           // Init UART0

    UART1Setup();           // Init UART1 and set it to use the alternate pins
    CH554UART1Alter();

    UART0_buf_init();       // Init UART0 and UART1 circular buffers
    UART1_buf_init();

    usb_protocol_reset();   // Reset the serial comms protocol


    USBSetup();             // Set up the USB CDC state machine

    SPIMasterModeSet(0);    // Configure SPI for master mode operation
    animations_initialize();

    systemTickSetup();

    // Note: inputs on port3 do not need to be initialized, since
    // they are set correctly be default.

    icn2053_begin();
    icn2053_setBrightness(brightness);
}



void main() {
    uint8_t temp;

    bool streamingMode = false;

    uint8_t geometryUpdateTimer = 0;
    uint8_t outputTimer = 0;

    uint8_t Uart_Timeout = 0;

    bool button1State = 1;
    bool button2State = 1;

    initBoard();

    while (1) {

/// Check buttons
        if((BUTTON1 == 0) && (button1State == 1)) {
            pattern++;
            patternChanged = true;

            if(animations_initialized) {
                if(pattern >= animations_count)
                    pattern = 0;
            }
            else if(pattern >= PATTERN_COUNT)
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
                Uart_Timeout++;     // Timer for buffering multiple uart rx bytes into a larger USB packet

            if(!UpPoint2_Busy)   //The endpoint is not busy (the first packet of data after idle, only used to trigger upload）
            {
                temp = UartByteCount;
                if(temp>0)
                {
                    if(temp>39 || Uart_Timeout>100)
                    {
                        Uart_Timeout = 0;
                        if(Uart_Output_Point+temp>UART_REV_LEN)
                            temp = UART_REV_LEN-Uart_Output_Point;
                        UartByteCount -= temp;
                        //Write upload endpoint
                        memcpy(Ep2Buffer+MAX_PACKET_SIZE,&Receive_Uart_Buf[Uart_Output_Point],temp);
                        Uart_Output_Point+=temp;
                        if(Uart_Output_Point>=UART_REV_LEN)
                            Uart_Output_Point = 0;
                        UEP2_T_LEN = temp;                                        //Pre-use send length must be cleared
                        UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;   //Answer ACK
                        UpPoint2_Busy = 1;
                    }
                }
            }
        }


// Handle system changes
        if(brightnessChanged) {
            brightnessChanged = false;
            icn2053_setBrightness(brightness);
        }

        if(patternChanged) {
            patternChanged = false;

            if(animations_initialized)
                animations_load(pattern);
        }

        if(frameReady) {
            frameReady = false;

            if(!streamingMode) {
                sendUpdateRight();

                if(animations_initialized) {
                    // Note: We're stomping on the protocol memory here...
                    animation_getFrame(usb_protocol_payloadData, frame);

                    for(temp = 0; temp < LED_COUNT; temp++)
                        ledData[streamToPhysical[temp]] = usb_protocol_payloadData[temp];
                }
                else {
                    if(pattern == 0)
                        marchingLetters();
                    else if(pattern == 1)
                        marchingLeds();
                }
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

            // If we are the master, and enough frames have elapsed, update the frame.
            if(!streamingMode
                    && (ledsToLeft == 0)
                    && (outputTimer > (animations_initialized ? animations_animation.speed : 4))) {
                outputTimer = 0;

                frame += 1;
                if((animations_initialized) && (frame >= animations_animation.frameCount))
                    frame = 0;

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
