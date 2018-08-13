#include "animations.h"
#include "spi_flash.h"
#include "leoblinky2018.h"

bool animations_initialized = false;
__idata uint8_t animations_count;

__idata struct AnimationHeader animations_animation;

void animations_initialize() {
    uint32_t temp;

    animations_initialized = false;

    // Test if the magic number is present
    Flash_Read(ANIMATIONS_TABLE_ADDRESS,
               sizeof(uint32_t),
               (void*) &temp);

    if (temp != ANIMATIONS_MAGIC_NUMBER)
        return;

    // Animation count
    Flash_Read(ANIMATIONS_TABLE_ADDRESS + sizeof(uint32_t),
               sizeof(uint32_t),
               (uint8_t*) &temp);

    if (temp > MAX_ANIMATIONS_COUNT)
        temp = MAX_ANIMATIONS_COUNT;

    animations_count = temp & 0xFF;

    animations_initialized = true;

    animations_load(0);
}

void animations_load(uint8_t animation) {

    if(animation >= animations_count)
        return;

    Flash_Read(ANIMATIONS_TABLE_ADDRESS + (2 + animation*ANIMATION_HEADER_SIZE)*sizeof(uint32_t),
               sizeof(struct AnimationHeader),
               (uint8_t*) animations_animation);

    animations_animation.speed = animations_animation.speed / SYSTEM_TICK_MS;
    if(animations_animation.speed == 0)
        animations_animation.speed = 1;
}

void animation_getFrame(uint8_t *buffer, uint16_t frame)
{
    // TODO: We're assuming that the frame size is equal to LED_COUNT
    Flash_Read(animations_animation.startingAddress + frame*LED_COUNT,
               LED_COUNT,
               buffer);
}
