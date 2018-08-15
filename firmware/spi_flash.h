#pragma once
#include <stdint.h>

uint8_t Flash_ReadStatusRegister();

void Flash_ReadJEDECID();

void Flash_EraseChip();

typedef struct {
    uint32_t address;
    uint32_t length;
    uint8_t* data;
} FlashConfig_t;

extern FlashConfig_t flash_config;

//void flash_read(uint32_t address, uint8_t length, uint8_t * flashData);
//void flash_write(uint32_t address, uint8_t length, uint8_t * flashData);
void flash_read();
void flash_write();

#define CMD_READJEDECID             (0x9F)
#define CMD_READSTATUSREGISTER      (0x05)

#define CMD_WRITE_ENABLE            (0x06)
#define CMD_WRITE_DISABLE           (0x04)

#define CMD_READDATA                (0x03)
#define CMD_READDATA_FAST           (0x0B)
#define CMD_PAGEPROGRAM             (0x02)

#define CMD_CHIP_ERASE              (0x60)


#define STATUS_REG_SRP          (1<<7)
#define STATUS_REG_B            (1<<5)
#define STATUS_REG_BP1          (1<<3)
#define STATUS_REG_BP2          (1<<2)
#define STATUS_REG_WEL          (1<<1)
#define STATUS_REG_BUSY         (1<<0)
