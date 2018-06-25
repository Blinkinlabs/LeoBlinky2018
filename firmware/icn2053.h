#pragma once

#include <stdint.h>

extern void icn2053_DataLatch(const uint16_t data);
//extern void icn2053_WriteDebugRegister();
extern void icn2053_Vsync();
extern void icn2053_WriteConfigRegister(uint8_t reg, uint16_t data);
//extern void icn2053_ReadConfigRegister(uint8_t reg, uint16_t &data);
extern void icn2053_EnableAllOutputChannels();
//extern void icn2053_DisableAllChannels();
extern void icn2053_PreActive();

extern void icn2053_begin();
extern void icn2053_updateDisplay(uint8_t *ledData, uint8_t ledCount);

#define REG1_OPEN_DET       0x4000          // LED open detect (0=disable, 1=enable)
#define REG1_ACC_RATEA      0x2000          // Accerate Rate (accelerate fix 9 rate, send 138 GCLKS eachline: set to 0)
#define REG1_SCAN_LINE(x)   ((x&0x1F)<<8)   // Number of scan lines (0=1 scan line, ... 31=32 scan lines) (5 bits)
#define REG1_OPT(x)         ((x&0x03)<<6)   // PWM Optimized Mode under low gray (0=disable, 1=recommended, 2, 3)
#define REG1_ACC_RATE(x)    ((x&0x03)<<4)   // Accelerate Rate (accelerate fix 8 rate, send 138 GCLKs each line: set to 0x3)
#define REG1_PWM_C          0x0008          // Color shift between board optimization (0=disable, 1=enable)

#define REG2_ADJ(x)         ((x&0x1F)<<10)  // Pre-charge for ghosting reduction level (Recommend R=31, G=28, B=23)
#define REG2_I_DIV4N        0x0200          // Current gain mode sleect (1=19*IGAIN/(Rext*256), 0=19*IGAIN/(REXT*1024))
#define REG2_IGAIN(x)       ((x&0xFF)<<1)   // Current gain adjust (IOUT=19*IGAIN/Rext*n, n set by REG2_I_DIV4N)

#define REG3_PWM_ALL(x)     ((x&0x0F)<<4)   // Low gray white balance adjust level (1-16), enabled by REG4_PWN_ADD_EN
#define REG3_UP_SEL         0x0004          // Ghosting reduction (0=disable, 1=enable)

#define REG4_PWM_ADD_EN     0x4000          // Low gray white balance adjust enable (0=disable, 1=enable)
#define REG4_OPEN_SCAN      0x0080          // LED open detect (LOD) (0=disable, 1=reset LOD circuit, enable
#define REG4_TRIM_ADD_EN    0x0008          // Constant current fine tune (0:IOUT=IOUT*(1+TRIM_ADJ*.4%), 0:IOUT=IOUT*(1-TRIM_ADJ*.4%)
#define REG4_TRIM_ADJ       ((x&0x03)<<0)   // Trim adjust
