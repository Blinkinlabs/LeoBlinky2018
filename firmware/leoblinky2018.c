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
