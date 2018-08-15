#include "animations.h"
#include "spi_flash.h"
#include "leoblinky2018.h"

#include <stdbool.h>

__bit animations_initialized = false;
uint8_t animations_count;

__idata struct AnimationHeader_t animations_animation;

void animations_initialize() {
    uint32_t temp;

    animations_initialized = false;

    // Test if the magic number is present
//    flash_read(ANIMATIONS_TABLE_ADDRESS,
//               sizeof(uint32_t),
//               (void*) &temp);
    flash_config.address = ANIMATIONS_TABLE_ADDRESS;
    flash_config.length = 4;
    flash_config.data = (void*) &temp;
    flash_read();

    if (temp != ANIMATIONS_MAGIC_NUMBER)
        return;

    // Animation count
//    flash_read(ANIMATIONS_TABLE_ADDRESS + sizeof(uint32_t),
//               sizeof(uint32_t),
//               (uint8_t*) &temp);
    flash_config.address = ANIMATIONS_TABLE_ADDRESS + 4;
    flash_config.length = 4;
    flash_config.data = (void*) &temp;
    flash_read();

    if (temp > MAX_ANIMATIONS_COUNT)
        temp = MAX_ANIMATIONS_COUNT;

    animations_count = temp & 0xFF;

    animations_initialized = true;

    animations_load(0);
}

void animations_load(uint8_t animation) {

    if(animation >= animations_count)
        return;

//    flash_read(ANIMATIONS_TABLE_ADDRESS + (2 + animation*ANIMATION_HEADER_SIZE)*sizeof(uint32_t),
//               sizeof(struct AnimationHeader),
//               (uint8_t*) animations_animation);
    flash_config.address = ANIMATIONS_TABLE_ADDRESS + 8 + animation*sizeof(struct AnimationHeader_t);
    flash_config.length = sizeof(struct AnimationHeader_t);
    flash_config.data = (uint8_t*) animations_animation;
    flash_read();

    animations_animation.delay = animations_animation.delay / SYSTEM_TICK_MS;
    if(animations_animation.delay == 0)
        animations_animation.delay = 1;
}

void animation_getFrame(uint16_t frame, uint8_t *buffer)
{
//    flash_read(animations_animation.startingAddress + frame*LED_COUNT,
//               LED_COUNT,
//               buffer);
    flash_config.address = animations_animation.startingAddress + frame*animations_animation.ledCount;

    if(LED_COUNT < animations_animation.ledCount)
        flash_config.length = LED_COUNT;
    else
        flash_config.length = animations_animation.ledCount;

    flash_config.data = buffer;
    flash_read();
}
