#include "patterns.h"
#include "leoblinky2018.h"

#include <float.h>
#include <math.h>
#include <stdint.h>


uint8_t step = 0;
//float phase = 0;

void fadeLeds() {
    uint8_t i;
    uint8_t brightness;

    step = ((frame >> 4) % (totalLeds()/2)) - ledsToLeft/2;
//    phase = frame / 10.0;

    // Note: Using 65535 here seemed to hang the processor
//    brightness = 250*powf(phase, 1.8);
    brightness = 255;

    for(i = 0; i < LED_PHYSICAL_CHANNELS; i++) {
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
        else {
            ledData[i] = 0;
        }
    }

#if 0
    phase += .01;
    if(phase > 1.0) {
        phase = 0.0;

        step = step + 1;
        if(step > 7)
            step = 0;
    }
#endif
}

void fadeLetters() {
    uint8_t i;
    uint8_t brightness;

    step = ((frame >> 5) % totalLetters()) - lettersToLeft;
    //phase = frame / 10.0;

    // Note: Using 65535 here seemed to hang the processor
//    brightness = 250*powf(phase, 1.8);
    brightness = 255;

    for(i = 0; i < LED_PHYSICAL_CHANNELS; i++) {
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
        else {
            ledData[i] = 0;
        }
    }

#if 0
    phase += .01;
    if(phase > 1.0) {
        phase = 0.0;

        step = step + 1;
        if(step > 2)
            step = 0;
    }
#endif
}




