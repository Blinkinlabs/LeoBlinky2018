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

#define ENABLE_USB

uint8_t uartByte;
__bit uartByteReady = false;

__code uint8_t brightnessSteps[] = {
    73,
    255,
    73,
    21,
    6,
    2,
    6,
    21,
};

__xdata uint8_t frameBuffer[LED_COUNT];

void sendByte(uint8_t byte) {
//    Receive_Uart_Buf[Uart_Input_Point++] = byte;
//    UartByteCount++;                    //Current buffer remaining bytes to be fetched
//    if(Uart_Input_Point>=UART_REV_LEN)
//        Uart_Input_Point = 0;           //Write pointer

    uartByte = byte;
    uartByteReady = true;
}

// Handle full messages here
void parsePayload() { //uint16_t dataSize, uint8_t* data) {
//    uint32_t address;
    uint8_t i;

    switch(usb_protocol_payloadData[0]) {
        case 0x00:  // Display some data on the LEDs
        {
            // Note: i counts backwards, and skips 0, so it should be set to the number
            // of LED bytes to copy. Example range: [14 13 12 11 10 9 8 7 6 5 4 3 2 1]
            i = usb_protocol_payloadLength;
            if(i > LED_COUNT)
                i = LED_COUNT;

            for(; i > 0; i--)
                ledData[streamToPhysical[i-1]] = usb_protocol_payloadData[i];

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

            flash_config.address = usb_protocol_payloadData[1];
            flash_config.address = flash_config.address << 8;
            flash_config.address |= usb_protocol_payloadData[2];
            flash_config.address = flash_config.address << 8;
            flash_config.address |= usb_protocol_payloadData[3];
            flash_config.address = flash_config.address << 8;
            flash_config.address |= usb_protocol_payloadData[4];

//            flash_write(address,
//                        FLASH_PAGESIZE,
//                        &usb_protocol_payloadData[5]);
            flash_config.length = FLASH_PAGESIZE;
            flash_config.data = &usb_protocol_payloadData[5];
            flash_write();

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
    if((BUTTON_STYLE == 0) && (BUTTON_SHINE == 0)) {
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

#if defined(ENABLE_USB)
    usb_protocol_reset();   // Reset the serial comms protocol

    USBSetup();             // Set up the USB CDC state machine
#endif

    SPIMasterModeSet(0);    // Configure SPI for master mode operation
    animations_initialize();

    systemTickSetup();

    // Note: inputs on port3 do not need to be initialized, since
    // they are set correctly be default.

    icn2053_begin();
    icn2053_setBrightness(brightnessSteps[brightnessIndex]);
}




void main() {
    static uint8_t temp;

    static __bit streamingMode = false;

    static uint8_t geometryUpdateTimer = 0;
    static uint8_t outputTimer = 0;

    static __bit buttonStyleState = 1;
    static __bit buttonShineState = 1;

    initBoard();

    while (1) {

/// Check buttons
        if((BUTTON_STYLE == 0) && (buttonStyleState == 1)) {
            pattern++;
            patternChanged = true;

            if(animations_initialized) {
                if(pattern >= animations_count)
                    pattern = 0;
            }
            else if(pattern >= PATTERN_COUNT)
                pattern = 0;
        }
        buttonStyleState = BUTTON_STYLE;

        if((BUTTON_SHINE == 0) && (buttonShineState == 1)) {
            brightnessIndex++;
            brightnessChanged = true;

            if(brightnessIndex >= sizeof(brightnessSteps))
                brightnessIndex = 0;
        }
        buttonShineState = BUTTON_SHINE;

// Check UARTS
        receiveLeft();
        receiveRight();

// Check USB
#if defined(ENABLE_USB)
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
//            if(UartByteCount)
//                Uart_Timeout++;     // Timer for buffering multiple uart rx bytes into a larger USB packet

            if(!UpPoint2_Busy)   //The endpoint is not busy (the first packet of data after idle, only used to trigger upload）
            {
//                temp = UartByteCount;
//                if(temp>0)
//                {
//                    if(temp>39 || Uart_Timeout>100)
//                    {
//                        Uart_Timeout = 0;
//                        if(Uart_Output_Point+temp>UART_REV_LEN)
//                            temp = UART_REV_LEN-Uart_Output_Point;
//                        UartByteCount -= temp;
//                        //Write upload endpoint
//                        memcpy(Ep2Buffer+MAX_PACKET_SIZE,&Receive_Uart_Buf[Uart_Output_Point],temp);
//                        Uart_Output_Point+=temp;
//                        if(Uart_Output_Point>=UART_REV_LEN)
//                            Uart_Output_Point = 0;
//                        UEP2_T_LEN = temp;                                        //Pre-use send length must be cleared
//                        UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;   //Answer ACK
//                        UpPoint2_Busy = 1;
//                    }
//                }

                if(uartByteReady)
                {
                    *(Ep2Buffer+MAX_PACKET_SIZE) = uartByte;
                    uartByteReady = false;

                    UEP2_T_LEN = 1;
                    UEP2_CTRL = UEP2_CTRL & ~ MASK_UEP_T_RES | UEP_T_RES_ACK;   //Answer ACK
                    UpPoint2_Busy = 1;
                }
            }
        }
#endif

        if(brightnessChanged) {
            brightnessChanged = false;
            icn2053_setBrightness(brightnessSteps[brightnessIndex]);
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

                if(animation_loaded) {
                    animation_getFrame(frame, frameBuffer);

                    for(temp = 0; temp < LED_COUNT; temp++)
                        ledData[streamToPhysical[temp]] = frameBuffer[temp];
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
                    && (outputTimer > (animation_loaded ? animations_animation.delay : 4))) {
                outputTimer = 0;

                frame += 1;
                if((animation_loaded) && (frame >= animations_animation.frameCount))
                    frame = 0;

                frameReady = true;
            }

            geometryUpdateTimer++;
            if(geometryUpdateTimer > GEOMETRY_UPDATE_TICKS) {
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
