#include "leoblinky2018.h"

#include <stdbool.h>

__xdata uint8_t ledData[LED_PHYSICAL_CHANNELS];

uint8_t ledsToLeft = 0;
uint8_t lettersToLeft = 0;
uint8_t ttlLeft = 0;

uint8_t ledsToRight = 0;
uint8_t lettersToRight = 0;
uint8_t ttlRight = 0;

uint8_t brightnessIndex = 0;

uint8_t pattern = 0;
uint16_t frame = 0;

__bit frameReady = false;
__bit brightnessChanged = false;
__bit patternChanged = false;



// Map from pattern stream to LED
// Note the map is defined by column- this is to make it easier to index into a
// pattern, for a specific badge
#if defined(VARIANT_DIS) || defined(VARIANT_ORI)

__code const uint8_t streamToPhysical[LED_COUNT] = {
    0, 14,
    1, 13,
    2, 12,
    3, 11,
    4, 10,
    5,  9,
    6,  8,
};

#elif defined(VARIANT_ENT)

__code const uint8_t streamToPhysical[LED_COUNT] = {
    0, 15,
    1, 14,
    2, 13,
    3, 12,
    4, 11,
    5, 10,
    6,  9,
    7,  8,
   16, 17,
};

#endif

void systemTickSetup()
{
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
}
