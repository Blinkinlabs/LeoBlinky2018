// Minimal implementation of the SPI Common Flash Interface (CFI)

#include <ch554.h>
#include <debug.h>
#include <spi.h>
#include "spi_flash.h"
#include "leoblinky2018.h"

FlashConfig_t flash_config;

uint8_t Flash_ReadStatusRegister()
{
    uint8_t status;

    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_READSTATUSREGISTER);
        status = CH554SPIMasterRead();      // Status register
    SPIMasterDeassertCS();

    return status;
}

void Flash_ReadJEDECID()
{
    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_READJEDECID);
        CH554SPIMasterRead();               // Manufacturer
        CH554SPIMasterRead();               // Memory type
        CH554SPIMasterRead();               // Capacity
    SPIMasterDeassertCS();
}

void Flash_EraseChip()
{
    // Enable write, and send chip erase command
    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_WRITE_ENABLE);
    SPIMasterDeassertCS();

    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_CHIP_ERASE);
    SPIMasterDeassertCS();

    while (Flash_ReadStatusRegister() & STATUS_REG_BUSY) {
        CH554WDTFeed(WDOG_FEED_TIME);
        mDelaymS(5);
    }
}

//void flash_read(uint32_t address, uint32_t length, uint8_t *flashData)
void flash_read()
{
    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_READDATA_FAST);
        CH554SPIMasterWrite(*((uint8_t*)&(flash_config.address) + 2));    // addr[23:16]
        CH554SPIMasterWrite(*((uint8_t*)&(flash_config.address) + 1));    // addr[15:8]
        CH554SPIMasterWrite(*((uint8_t*)&(flash_config.address) + 0));    // addr[7:0]
        CH554SPIMasterWrite(0x00);              // Wait states
        for(;flash_config.length > 0; flash_config.length--) {
            *flash_config.data = CH554SPIMasterRead();
            flash_config.data++;
        }
    SPIMasterDeassertCS();
}

//void flash_write(uint32_t address, uint32_t length, uint8_t *flashData)
void flash_write()
{
    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_WRITE_ENABLE);
    SPIMasterDeassertCS();

    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_PAGEPROGRAM);
        CH554SPIMasterWrite(*((uint8_t*)&(flash_config.address) + 2));    // addr[23:16]
        CH554SPIMasterWrite(*((uint8_t*)&(flash_config.address) + 1));    // addr[15:8]
        CH554SPIMasterWrite(*((uint8_t*)&(flash_config.address) + 0));    // addr[7:0]
        for(;flash_config.length > 0; flash_config.length--) {
            CH554SPIMasterWrite(*flash_config.data);
            flash_config.data++;
        }
    SPIMasterDeassertCS();

    while (Flash_ReadStatusRegister() & STATUS_REG_BUSY)
        mDelaymS(5);
}
