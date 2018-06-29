// Minimal implementation of the SPI Common Flash Interface (CFI)

#include <ch554.h>
#include <debug.h>
#include <spi.h>
#include "spi_flash.h"


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
        mDelaymS(10);
    }
}

void Flash_Read(uint32_t address, uint32_t length, uint8_t *flashData)
{
    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_ARRAYREAD);
        CH554SPIMasterWrite(*((uint8_t*)&(address) + 1));    // addr[23:16]
        CH554SPIMasterWrite(*((uint8_t*)&(address) + 2));    // addr[15:8]
        CH554SPIMasterWrite(*((uint8_t*)&(address) + 3));    // addr[7:0]
        CH554SPIMasterWrite(0x00);              // Wait states
        for(;length > 0; length--) {
            *flashData = CH554SPIMasterRead();
            flashData++;
        }
    SPIMasterDeassertCS();
}

void Flash_Write(uint32_t address, uint32_t length, uint8_t *flashData)
{
    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_WRITE_ENABLE);
    SPIMasterDeassertCS();

    SPIMasterAssertCS();
        CH554SPIMasterWrite(CMD_PAGEPROGRAM);
        CH554SPIMasterWrite(*((uint8_t*)&(address) + 1));    // addr[23:16]
        CH554SPIMasterWrite(*((uint8_t*)&(address) + 2));    // addr[15:8]
        CH554SPIMasterWrite(*((uint8_t*)&(address) + 3));    // addr[7:0]
        for(;length > 0; length--) {
            CH554SPIMasterWrite(*flashData);
            flashData++;
        }
    SPIMasterDeassertCS();

    while (Flash_ReadStatusRegister() & STATUS_REG_BUSY)
        ;
}
