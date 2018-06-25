#include <ch554.h>
#include <debug.h>
#include <bootloader.h>

#include "uart0_int.h"
#include "uart1_int.h"

#include "leoblinky2018.h"
#include "icn2053.h"
#include "comms.h"
#include "patterns.h"

void initBoard() {
    CfgFsys();

    //UART0Setup();
    mInitSTDIO();
    UART1Setup();
    CH554UART1Alter();

    UART0_buf_init();
    UART1_buf_init();


    // Configure Timer2 for GCLK generation at 4MHz
    RCLK = 0;
    TCLK = 0;

    T2MOD |= bTMR_CLK | bT2_CLK | T2OE;
    RCAP2L = 254;
    RCAP2H = 255;
    TL2 = 254;
    TH2 = 255;


    // Configure output pins on port 1
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
}

void main() {
    uint8_t c = 0;
    uint8_t tickTimer = 0; // TODO: replace me with timer

    initBoard();

    while (1) {
        if(BUTTON1 == 0) {
            pattern++;
            if(pattern == PATTERN_COUNT)
                pattern = 0;
        }
       
        // TODO: Should be brightness.
        if(BUTTON2 == 0) {
            EA = 0;
            bootloader();
        }

#if 0
        // Loop UART0 RX to UART1 TX
        if(UART0_buf_read(&c))
            UART1_buf_write(c);

        // And loop UART1 RX to UART0 TX
        if(UART1_buf_read(&c))
            UART0_buf_write(c);
#endif


        if(pattern == 0)
            fadeLetters();
        else if(pattern == 1)
            fadeLeds();

        icn2053_updateDisplay(ledData, LED_COUNT);

        tickTimer++;

        if(tickTimer > 30) {
            tickTimer = 0;

            sendGeometryLeft();
            sendGeometryRight();
//            sendUpdateRight();
        }

        mDelaymS(30);   // Aim for some framerate
    }
}
