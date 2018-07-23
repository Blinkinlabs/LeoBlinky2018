#pragma once

#include <stdint.h>

//extern void icn2053_DataLatch(const uint16_t data);
////extern void icn2053_WriteDebugRegister();
//extern void icn2053_Vsync();
//extern void icn2053_WriteConfigRegister(uint8_t reg, uint16_t data);
////extern void icn2053_ReadConfigRegister(uint8_t reg, uint16_t &data);
//extern void icn2053_EnableAllOutputChannels();
////extern void icn2053_DisableAllChannels();
//extern void icn2053_PreActive();

extern void icn2053_begin();
extern void icn2053_setBrightness(uint8_t brightness);
extern void icn2053_updateDisplay(uint8_t *ledData);
