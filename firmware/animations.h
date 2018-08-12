
#include <stdint.h>
#include <stdbool.h>

// Max. number of animations that can be read from the flash (arbitrary)
#define MAX_ANIMATIONS_COUNT 20

// Address in flash memory of the Animations table
#define ANIMATIONS_TABLE_ADDRESS    0x00000000

// Number of uint32_t fields per animat`ion in the animation table
#define ANIMATION_HEADER_SIZE 3

#define ANIMATIONS_MAGIC_NUMBER 0x12345679

// Animations table is an array of uint32_t integers, and looks like this:
// Note that entries are 4 bytes each.
// 0: magic number (0x12345678)
// 1: animation count (number of animations in table)
// 2 + n*3: animation n: frameCount
// 2 + n*3: animation n: speed
// 2 + n*3: animation n: flashAddress

struct AnimationHeader {
   uint32_t frameCount;
   uint32_t speed;
   uint32_t startingAddress;
};

//// Variables for the animation table
///
extern bool animations_initialized;         // True if the animation system is loaded
extern __idata uint8_t animations_count;    // Number of animations in this class

void animations_initialize();        // Re-read the animation table data
void animations_load(uint8_t animation);           // Set the current animation

//// Variables for the current animation

extern __idata struct AnimationHeader animations_animation;

void animation_getFrame(uint8_t* buffer, uint16_t frame);      // Load the frame data from this animation
