#include "patterns.h"
#include "leoblinky2018.h"

#include <stdint.h>
#include "uart1_int.h"

void fadeLeds() {
    uint8_t i;
    uint8_t step = ((frame >> 1) % (totalLeds()/2)) - ledsToLeft/2;

    for(i = 0; i < LED_PHYSICAL_CHANNELS; i++) {
        if((step == 0) && (i==0 || i == 14))
                ledData[i] = 255;
        else if((step == 1) && (i == 1 || i == 13))
                ledData[i] = 255;
        else if ((step == 2) && (i == 2 || i == 12))
                ledData[i] = 255;
        else if((step == 3) && (i==3 || i == 11))
                ledData[i] = 255;
        else if((step == 4) && (i==4 || i == 10))
                ledData[i] = 255;
        else if((step == 5) && (i == 5 || i == 9))
                ledData[i] = 255;
        else if((step == 6) && (i == 6 || i == 8))
                ledData[i] = 255;
        else
            ledData[i] = 0;
    }
}

void fadeLetters() {
    uint8_t i;
    uint8_t step = ((frame >> 4) % totalLetters()) - lettersToLeft;

    for(i = 0; i < LED_PHYSICAL_CHANNELS; i++) {
        if((step == 0) && (i==0 || i == 1 || i == 2 || i == 12 || i == 13 || i == 14))
                ledData[i] = 255;
        else if((step == 1) && (i==3 || i == 11))
                ledData[i] = 255;
        else if((step == 2) && (i==4 || i == 5 || i == 6 || i == 8 || i == 9 || i == 10))
                ledData[i] = 255;
        else
            ledData[i] = 0;
    }
}




