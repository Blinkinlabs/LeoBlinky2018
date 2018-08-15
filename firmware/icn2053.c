#include <ch554.h>
#include <debug.h>
#include "icn2053.h"
#include "leoblinky2018.h"

#include "brightness_table.h"

#define REG1_OPEN_DET       0x4000          // LED open detect (0=disable, 1=enable)
#define REG1_ACC_RATEA      0x2000          // Accerate Rate (accelerate fix 9 rate, send 138 GCLKS eachline: set to 0)
#define REG1_SCAN_LINE(x)   ((x&0x1F)<<8)   // Number of scan lines (0=1 scan line, ... 31=32 scan lines) (5 bits)
#define REG1_OPT(x)         ((x&0x03)<<6)   // PWM Optimized Mode under low gray (0=disable, 1=recommended, 2, 3)
#define REG1_ACC_RATE(x)    ((x&0x03)<<4)   // Accelerate Rate (accelerate fix 8 rate, send 138 GCLKs each line: set to 0x3)
#define REG1_PWM_C          0x0008          // Color shift between board optimization (0=disable, 1=enable)

#define REG2_ADJ(x)         ((x&0x1F)<<10)  // Pre-charge for ghosting reduction level (Recommend R=31, G=28, B=23)
#define REG2_I_DIV4N        0x0200          // Current gain mode sleect (1=19*IGAIN/(Rext*256), 0=19*IGAIN/(REXT*1024))
#define REG2_IGAIN(x)       ((x&0xFF)<<1)   // Current gain adjust (IOUT=19*IGAIN/Rext*n, n set by REG2_I_DIV4N)
#define REG2_TEST           0x0001

#define REG3_PWM_ALL(x)     ((x&0x0F)<<4)   // Low gray white balance adjust level (1-16), enabled by REG4_PWN_ADD_EN
#define REG3_UP_SEL         0x0004          // Ghosting reduction (0=disable, 1=enable)

#define REG4_PWM_ADD_EN     0x4000          // Low gray white balance adjust enable (0=disable, 1=enable)
#define REG4_OPEN_SCAN      0x0080          // LED open detect (LOD) (0=disable, 1=reset LOD circuit, enable
#define REG4_TRIM_ADD_EN    0x0008          // Constant current fine tune (0:IOUT=IOUT*(1+TRIM_ADJ*.4%), 1:IOUT=IOUT*(1-TRIM_ADJ*.4%)
#define REG4_TRIM_ADJ       ((x&0x03)<<0)   // Trim adjust

//extern void icn2053_DataLatch(const uint16_t data);
//extern void icn2053_WriteDebugRegister();
extern void icn2053_Vsync();
extern void icn2053_WriteConfigRegister(uint8_t reg, uint16_t data);
//extern void icn2053_ReadConfigRegister(uint8_t reg, uint16_t &data);
extern void icn2053_EnableAllOutputChannels();
//extern void icn2053_DisableAllChannels();
extern void icn2053_PreActive();


#define clockBit(data, bit) \
    LED_MOSI = data & (1 << bit); \
    LED_CLK = 1;    \
    LED_CLK = 0;

void sendLatchedPulses(uint8_t pulses) {
    // TODO: Are these necessicary? They were included in the datasheet for a different part
    LED_CLK = 1;
    LED_CLK = 0;

    LED_LE = 1;
    for(; pulses > 0; pulses--) {
        LED_CLK = 1;
        LED_CLK = 0;
    }
    LED_LE = 0;

    LED_CLK = 1;
    LED_CLK = 0;
}

void sendLatchedData(const uint16_t data, int8_t latchedBits) {
    int8_t bits;

    // Unrolled loop for when we're sending data
    // (most common cases)
    if(latchedBits == 0) {
        clockBit(data, 15);
        clockBit(data, 14);
        clockBit(data, 13);
        clockBit(data, 12);
        clockBit(data, 11);
        clockBit(data, 10);
        clockBit(data, 9);
        clockBit(data, 8);
        clockBit(data, 7);
        clockBit(data, 6);
        clockBit(data, 5);
        clockBit(data, 4);
        clockBit(data, 3);
        clockBit(data, 2);
        clockBit(data, 1);
        clockBit(data, 0);
        return;
    }
    if(latchedBits == 1) {
        clockBit(data, 15);
        clockBit(data, 14);
        clockBit(data, 13);
        clockBit(data, 12);
        clockBit(data, 11);
        clockBit(data, 10);
        clockBit(data, 9);
        clockBit(data, 8);
        clockBit(data, 7);
        clockBit(data, 6);
        clockBit(data, 5);
        clockBit(data, 4);
        clockBit(data, 3);
        clockBit(data, 2);
        clockBit(data, 1);
        LED_LE = 1;
        clockBit(data, 0);
        LED_LE = 0;
        return;
    }

    latchedBits--;

    // TODO: Test me.
    // 16 bits of data, with LE held high for latchCount bits
    for(bits = 15; bits >= 0; bits--) {

        LED_MOSI = data & (1 << bits);

        if(bits == latchedBits)
            LED_LE = 1;

        LED_CLK = 1;
        LED_CLK = 0;
    }
    LED_LE = 0;
}

void icn2053_Vsync() {
    sendLatchedPulses(3);
}

void icn2053_WriteConfigRegister(uint8_t reg, uint16_t data) {
    uint8_t chip;
    const uint8_t latches = 2 + reg*2;

    icn2053_PreActive();

    for(chip = ICN2053_COUNT; chip != 255; chip--) {
        if(chip != 0)
            sendLatchedData(data, 0);
        else
            sendLatchedData(data, latches);
    }
}


void icn2053_EnableAllOutputChannels() {
    icn2053_PreActive();
    sendLatchedPulses(12);
}


void icn2053_PreActive() {
    sendLatchedPulses(14);
}


void icn2053_begin() {
    // Configure Timer2 for GCLK generation at 4MHz
    RCLK = 0;
    TCLK = 0;

    T2MOD |= bTMR_CLK | bT2_CLK | T2OE;
    RCAP2L = 254;
    RCAP2H = 255;
    TL2 = 254;
    TH2 = 255;

    // Configure output pins on port
    P1_MOD_OC = P1_MOD_OC
                & ~(1<<LED_CLK_PIN)
                & ~(1<<LED_MOSI_PIN)
                & ~(1<<LED_LE_PIN)
                & ~(1<<LED_GCLK_PIN);
    P1_DIR_PU = P1_DIR_PU
                | (1<<LED_CLK_PIN)
                | (1<<LED_MOSI_PIN)
                | (1<<LED_LE_PIN)
                | (1<<LED_GCLK_PIN);

    LED_CLK = 0;
    LED_MOSI = 0;
    LED_LE = 0;

    // TODO: actually configure anything

    icn2053_WriteConfigRegister(1, REG1_SCAN_LINE(0) | REG1_OPT(1) | REG1_ACC_RATE(0x3));
//    icn2053_WriteConfigRegister(1, 0x1F70);     // Should be defaults
//    icn2053_WriteConfigRegister(2, 0x7FFF);
//    icn2053_WriteConfigRegister(3, 0x4007);
//    icn2053_WriteConfigRegister(4, 0x0040);

    icn2053_EnableAllOutputChannels();
}

void icn2053_setBrightness(uint8_t brightness) {
    icn2053_WriteConfigRegister(2, REG2_ADJ(0x1F) | REG2_I_DIV4N | REG2_IGAIN(brightness) | REG2_TEST);
}

void icn2053_updateDisplay(uint8_t* ledData) {
    uint8_t led;
    uint8_t chip;

    uint16_t expandedData;

    for(led = 15; led !=255; led--) {
        for(chip = ICN2053_COUNT; chip != 255; chip--) {
            expandedData = brightnessTable[ledData[chip*16 + led]];

            if(chip != 0)
                sendLatchedData(expandedData, 0);
            else
                sendLatchedData(expandedData, 1);
        }
    }

    mDelayuS(150);       // Macroblock app note says 50GCLK needed between last last and VSYNC

    TR2 = 0;    // Disable GCLK

    icn2053_Vsync();
    mDelayuS(150);       // Macroblock app note says 100ns needed between VSYNC and GCLK start

    TR2 = 1;    // Enable GCLK
}
