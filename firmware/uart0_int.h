#pragma once

#include <stdint.h>
#include <stdbool.h>

#ifndef UART0_RX_LEN
#define UART0_RX_LEN 4
#endif

#ifndef UART0_TX_LEN
#define UART0_TX_LEN 4
#endif

extern volatile __idata uint8_t UART0_rx_byte_count;

extern void UART0_buf_init();

extern bool UART0_buf_read(uint8_t *c);

extern bool UART0_buf_write(const uint8_t c);


// Make sure SDCC can find the interrupt
void UART0_ISR(void) __interrupt (INT_NO_UART0);
