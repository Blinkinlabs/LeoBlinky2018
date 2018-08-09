#include "leoblinky2018.h"

__xdata uint8_t ledData[LED_PHYSICAL_CHANNELS];

uint8_t ledsToLeft;
uint8_t lettersToLeft;
uint8_t ttlLeft;

uint8_t ledsToRight;
uint8_t lettersToRight;
uint8_t ttlRight;

uint8_t brightness;

uint8_t pattern;
uint16_t frame;

bool frameReady;
bool brightnessChanged;

#if defined(VARIANT_DIS)

__code const uint8_t streamToPhysical[LED_COUNT] = {
     0,  1,  2,  3,  4,  5,  6,
    14, 13, 12, 11, 10,  9,  8,
};

#elif defined(VARIANT_ORI)

__code const uint8_t streamToPhysical[LED_COUNT] = {
     0,  1,  2,  3,  4,  5,  6,
    14, 13, 12, 11, 10,  9,  8,
};

#elif defined(VARIANT_ENT)

__code const uint8_t streamToPhysical[LED_COUNT] = {
     0,  1,  2,  3,  4,  5,  6, 16,
    14, 13, 12, 11, 10,  9,  8, 17,
};

#endif
