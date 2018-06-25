#include <ch554.h>
#include <debug.h>
#include <bootloader.h>

#include <float.h>
#include <math.h>

#include "uart0_int.h"
#include "uart1_int.h"

#include "leoblinky2018.h"
#include "icn2053.h"

uint8_t ledData[LED_COUNT];


// Commands:
// Command         size header byte1            byte 2              byte 3
// LEFT_GEOMETRY    3   [0x01] [ledsToLeft]     [lettersToLeft]     [brightness]
// RIGHT_GEOMETRY   3   [0x02] [ledsToRight]    [lettersToRight]
// UPDATE           4   [0x03] [pattern]        [frameH]            [frameL]

#define LEFT_GEOMETRY_HEADER    0x01
#define RIGHT_GEOMETRY_HEADER   0x02
#define UPDATE_HEADER           0x03

uint8_t ledsToLeft;
uint8_t lettersToLeft;
uint8_t ttlLeft;

uint8_t ledsToRight;
uint8_t lettersToRight;
uint8_t ttlRight;

uint8_t brightness;

#define PATTERN_COUNT           2
uint8_t pattern;

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
    RCAP2L = 254; // TODO: Set these to the number of PWM counts in a full cycle, so we can use T2 interrupt to update the display
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

#if 0
    // Configure bi-directional pinson port 3
    P3_DIR_PU = P3_DIR_PI
                | (1<<BUTTON1_PIN)
                | (1<<BUTTON2_PIN);
    P3_MOD_OC = P3_MOD_OC
                (1<<BUTTON1_PIN)
                | (1<<BUTTON2_PIN);
#endif

    LED_CLK = 0;
    LED_MOSI = 0;
    LED_LE = 0;

    ledsToLeft = 0;
    lettersToLeft = 0;
    ttlLeft = 0;

    ledsToRight = 0;
    lettersToRight = 0;
    ttlRight = 0;

    brightness = 255;
}

void fadeLeds() {
    static uint8_t step = 0;
    static float phase = 0;

    uint8_t i;
    uint8_t brightness;

    // Note: Using 65535 here seemed to hang the processor
    brightness = 250*powf(phase, 1.8);

    for(i = 0; i < LED_COUNT; i++) {
        if (step == 0) {
            if(i==0 || i == 14)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        if (step == 1) {
            if(i == 1 || i == 13)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        if (step == 2) {
            if(i == 2 || i == 12)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        else if(step == 3) {
            if(i==3 || i == 11)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        else if(step == 4) {
            if(i==4 || i == 10)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        else if(step == 5) {
            if(i == 5 || i == 9)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        else if(step == 6) {
            if(i == 6 || i == 8)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
    }

    phase += .001;
    if(phase > 1.0) {
        phase = 0.0;

        step = step + 1;
        if(step > 7)
            step = 0;
    }

}

void fadeLetters() {
    static uint8_t step = 0;
    static float phase = 0;

    uint8_t i;
    uint8_t brightness;

    // Note: Using 65535 here seemed to hang the processor
    brightness = 250*powf(phase, 1.8);

    for(i = 0; i < LED_COUNT; i++) {
        if (step == 0) {
            if(i==0 || i == 1 || i == 2 || i == 12 || i == 13 || i == 14)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        else if(step == 1) {
            if(i==3 || i == 11)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
        else if(step == 2) {
            if(i==4 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10)
                ledData[i] = brightness;
            else
                ledData[i] = 0;
        }
    }

    phase += .001;
    if(phase > 1.0) {
        phase = 0.0;

        step = step + 1;
        if(step > 2)
            step = 0;
    }
}


void sendGeometryLeft() {
    // UART1 on left
    UART1_buf_write(RIGHT_GEOMETRY_HEADER);
    UART1_buf_write(lettersToRight + LED_COUNT);
    UART1_buf_write(lettersToRight + LETTER_COUNT);
}


void sendGeometryRight() {
    // UART0 on right
    UART0_buf_write(LEFT_GEOMETRY_HEADER);
    UART0_buf_write(lettersToLeft + LED_COUNT);
    UART0_buf_write(lettersToLeft + LETTER_COUNT);
    UART0_buf_write(brightness);
}


void main() {
    uint8_t c = 0;

    uint8_t frameCount = 0; // TODO: replace me with timer
    pattern = 0;

    initBoard();

    icn2053_begin();

    UART0_buf_write('0');
    UART1_buf_write('1');

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

        frameCount++;

        if(frameCount > 50) {
            frameCount = 0;

//            sendGeometryLeft();
//            sendGeometryRight();
//            sendUpdateRight();
        }

//        mDelaymS(30);   // Aim for some framerate
    }
}
