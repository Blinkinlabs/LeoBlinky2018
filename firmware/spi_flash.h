#pragma once
#include <stdint.h>

extern uint8_t Flash_ReadStatusRegister();

extern void Flash_ReadJEDECID();

extern void Flash_EraseChip();

extern void Flash_Read(uint32_t address, uint32_t length, uint8_t * flashData);
extern void Flash_Write(uint32_t address, uint32_t length, uint8_t * flashData);

#define CMD_READJEDECID             (0x9F)
#define CMD_READSTATUSREGISTER      (0x05)

#define CMD_WRITE_ENABLE            (0x06)
#define CMD_WRITE_DISABLE           (0x04)

#define CMD_ARRAYREAD               (0x0B)
#define CMD_PAGEPROGRAM             (0x02)

#define CMD_CHIP_ERASE              (0x60)


#define STATUS_REG_SRP          (1<<7)
#define STATUS_REG_B            (1<<5)
#define STATUS_REG_BP1          (1<<3)
#define STATUS_REG_BP2          (1<<2)
#define STATUS_REG_WEL          (1<<1)
#define STATUS_REG_BUSY         (1<<0)
