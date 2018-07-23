#include "patterns.h"
#include "leoblinky2018.h"

#include <stdint.h>
#include "uart1_int.h"

#if defined(VARIANT_DIS)

__code const uint8_t ledToLetter[LED_PHYSICAL_CHANNELS] = {
    0, 0, 0, 1, 2, 2, 2, 255,
    2, 2, 2, 1, 0, 0, 0, 255,
};

__code const uint8_t ledToCoordinate[LED_PHYSICAL_CHANNELS*2] = {
    0,0,    // LED 0
    1,0,
    2,0,
    3,0,
    4,0,
    5,0,
    6,0,
    255,255,
    6,1,
    5,1,
    4,1,
    3,1,
    2,1,
    1,1,
    0,1,
    255,255,
};

#elif defined(VARIANT_ORI)

__code const uint8_t ledToLetter[LED_PHYSICAL_CHANNELS] = {
    0, 0, 0, 1, 1, 1, 2, 255,
    2, 1, 1, 1, 0, 0, 0, 255,
};

__code const uint8_t ledToCoordinate[LED_PHYSICAL_CHANNELS*2] = {
    0,0,    // LED 0
    1,0,
    2,0,
    3,0,
    4,0,
    5,0,
    6,0,
    255,255,
    6,1,
    5,1,
    4,1,
    3,1,
    2,1,
    1,1,
    0,1,
    255,255,
};

#elif defined(VARIANT_ENT)

__code const uint8_t ledToLetter[LED_PHYSICAL_CHANNELS] = {
    0, 0, 0, 1, 1, 1, 2, 2,         // LEDs 0-8
    2, 2, 1, 1, 1, 0, 0, 0,         // LEDs 9-15
    2, 2,                           // LEDs 16-17
    255, 255, 255, 255, 255, 255, 255,  // Remaining unused LEDs
    255, 255, 255, 255, 255, 255, 255,
};

__code const uint8_t ledToCoordinate[LED_PHYSICAL_CHANNELS*2] = {
    0,0,    // LED 0
    1,0,
    2,0,
    3,0,
    4,0,
    5,0,
    6,0,
    7,0,
    7,1,
    6,1,
    5,1,
    4,1,
    3,1,
    2,1,
    1,1,
    0,1,
    8,0,    // LED 16
    8,1,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
    255,255,
};

#endif

void marchingLeds() {
    uint8_t i;
    uint8_t step = ((frame >> 1) % (totalLeds()/2)) - ledsToLeft/2;

    for(i = 0; i < LED_PHYSICAL_CHANNELS; i++) {
        if(step == ledToCoordinate[i*2 + 0])
            ledData[i] = 255;
        else
            ledData[i] = 0;
    }
}

void marchingLetters() {
    uint8_t i;
    uint8_t step = ((frame >> 4) % totalLetters()) - lettersToLeft;

    for(i = 0; i < LED_PHYSICAL_CHANNELS; i++) {
        if(step == ledToLetter[i])
            ledData[i] = 255;
        else
            ledData[i] = 0;
    }
}




