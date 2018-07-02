#include <ch554.h>
#include <debug.h>
#include <bootloader.h>

#include "uart0_int.h"
#include "uart1_int.h"

#include "leoblinky2018.h"
#include "icn2053.h"
#include "comms.h"
#include "patterns.h"
#include "spi.h"
#include "spi_flash.h"

void initBoard() {
    CfgFsys();

    //UART0Setup();
    mInitSTDIO();
    UART1Setup();
    CH554UART1Alter();

    UART0_buf_init();
    UART1_buf_init();

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
    uint8_t geometryUpdateTimer = 0;
    uint8_t outputTimer = 0;

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

        receiveLeft();
        receiveRight();

        if(brightnessChanged) {
            brightnessChanged = false;
            icn2053_setBrightness(brightness);
        }

        if(frameReady) {
            frameReady = false;

            sendUpdateRight();

            if(pattern == 0)
                fadeLetters();
            else if(pattern == 1)
                fadeLeds();

            icn2053_updateDisplay(ledData, LED_PHYSICAL_CHANNELS);
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
            if((ledsToLeft == 0) && (outputTimer > 3)) {
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
