#pragma once

#include <stdint.h>

//void icn2053_DataLatch(const uint16_t data);
////void icn2053_WriteDebugRegister();
//void icn2053_Vsync();
//void icn2053_WriteConfigRegister(uint8_t reg, uint16_t data);
////void icn2053_ReadConfigRegister(uint8_t reg, uint16_t &data);
//void icn2053_EnableAllOutputChannels();
////void icn2053_DisableAllChannels();
//void icn2053_PreActive();

void icn2053_begin();
void icn2053_setBrightness(uint8_t brightness);
void icn2053_updateDisplay(uint8_t *ledData);
