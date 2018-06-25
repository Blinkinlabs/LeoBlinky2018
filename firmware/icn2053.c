#include <ch554.h>
#include <debug.h>
#include "icn2053.h"
#include "leoblinky2018.h"

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
    // (most common case)
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


void icn2053_DataLatch(const uint16_t data) {
    sendLatchedData(data, 1);
}


void icn2053_Vsync() {
    sendLatchedPulses(3);
}

void icn2053_WriteConfigRegister(uint8_t reg, uint16_t data) {
    const uint8_t latches = 2 + reg*2;
    icn2053_PreActive();
    sendLatchedData(data, latches);
}


void icn2053_EnableAllOutputChannels() {
    icn2053_PreActive();
    sendLatchedPulses(12);
}


void icn2053_PreActive() {
    sendLatchedPulses(14);
}


void icn2053_begin() {
    // TODO: actually configure anything

    icn2053_WriteConfigRegister(1, REG1_SCAN_LINE(0) | REG1_OPT(1) | REG1_ACC_RATE(0x3));
//    icn2053_WriteConfigRegister(1, 0x1F70);     // Should be defaults
//    icn2053_WriteConfigRegister(2, 0x7FFF);
//    icn2053_WriteConfigRegister(3, 0x4007);
//    icn2053_WriteConfigRegister(4, 0x0040);

    icn2053_EnableAllOutputChannels();
}

void icn2053_updateDisplay(uint8_t* leds, uint8_t ledCount) {
    uint16_t expandedData;

    for(; ledCount > 0; ledCount--) {
        expandedData = leds[ledCount-1] << 8;
        icn2053_DataLatch(expandedData);
    }

    mDelayuS(150);       // Macroblock app note says 50GCLK needed between last last and VSYNC

    TR2 = 0;    // Disable GCLK

    icn2053_Vsync();
    mDelayuS(150);       // Macroblock app note says 100ns needed between VSYNC and GCLK start

    TR2 = 1;    // Enable GCLK
}
