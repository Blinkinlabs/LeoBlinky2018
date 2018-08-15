#include <stdint.h>

// Max. number of animations that can be read from the flash (arbitrary)
#define MAX_ANIMATIONS_COUNT 255

// Address in flash memory of the Animations table
#define ANIMATIONS_TABLE_ADDRESS    0x00000000

// Number of uint32_t fields per animat`ion in the animation table
#define ANIMATION_HEADER_SIZE 3

#define ANIMATIONS_MAGIC_NUMBER 0x12345678

// Animations table looks like this:
// Note that entries are 4 bytes each.
// 0: magic number (0x12345678)
// 4: animation count (number of animations in table)
// 8 + n*10: animation n: frameCount
// 8 + n*10: animation n: speed
// 8 + n*10: animation n: flashAddress

struct AnimationHeader_t {
   uint16_t frameCount;
   uint16_t ledCount;
   uint16_t delay;
   uint32_t startingAddress;
};

//// Variables for the animation table
///
extern __bit animations_initialized;         // True if the animation system is loaded
extern uint8_t animations_count;    // Number of animations in this class

void animations_initialize();        // Re-read the animation table data
void animations_load(uint8_t animation);           // Set the current animation

//// Variables for the current animation

extern __idata struct AnimationHeader_t animations_animation;

void animation_getFrame(uint16_t frame, uint8_t* buffer);      // Load the frame data from this animation
