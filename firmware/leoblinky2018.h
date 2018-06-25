#pragma once

#include <ch554.h>
#include <stdint.h>

#define PORT1_BASE  0x90
#define PORT2_BASE  0xA0
#define PORT3_BASE  0xB0

// LED pins use GPIO bitbanging
#define LED_CLK_PIN     3   // P1.3
#define LED_MOSI_PIN    1   // P1.1
#define LED_LE_PIN      2   // P1.2
#define LED_GCLK_PIN    0   // P1.0

SBIT(LED_CLK, PORT1_BASE, LED_CLK_PIN);
SBIT(LED_MOSI, PORT1_BASE, LED_MOSI_PIN);
SBIT(LED_LE, PORT1_BASE, LED_LE_PIN);
SBIT(LED_GCLK, PORT1_BASE, LED_GCLK_PIN);

// Flash pins use SPI peripheral
#define FLASH_CS_PIN    4   // P1.4
#define FLASH_MOSI_PIN  5   // P1.5
#define FLASH_MISO_PIN  6   // P1.6
#define FLASH_SCK_PIN   7   // P1.7

// TX and RX pins use UART0 and UART1 peripherals
#define TXD1_PIN        2   // P3.2, UART1 alt mode
#define RXD1_PIN        4   // P3.4, UART1 alt mode
#define TXD_PIN         1   // P3.1, UART0 mode
#define RXD_PIN         0   // P3.0, UART0 mode

// Button pins are GPIO inputs
#define BUTTON1_PIN     5   // P3.5
#define BUTTON2_PIN     3   // P3.3

SBIT(BUTTON1, PORT3_BASE, BUTTON1_PIN);
SBIT(BUTTON2, PORT3_BASE, BUTTON2_PIN);

#define SCANLINE_COUNT 1
#define LED_COUNT 16

#define LETTER_COUNT 3

extern uint8_t ledData[LED_COUNT];

extern uint8_t ledsToLeft;
extern uint8_t lettersToLeft;
extern uint8_t ttlLeft;

extern uint8_t ledsToRight;
extern uint8_t lettersToRight;
extern uint8_t ttlRight;

extern uint8_t brightness;

extern uint8_t pattern;
extern uint16_t frame;

