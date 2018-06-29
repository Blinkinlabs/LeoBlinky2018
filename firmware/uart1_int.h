#pragma once

#include <ch554.h>
#include <stdint.h>
#include <stdbool.h>
#include "circular_buffer.h"

#ifndef UART1_RX_LEN
#define UART1_RX_LEN 8
#endif

#ifndef UART1_TX_LEN
#define UART1_TX_LEN 4
#endif

extern volatile __idata uint8_t UART1_rx_byte_count;

extern void UART1_buf_init();

extern bool UART1_buf_read(uint8_t *c);

extern bool UART1_buf_write(const uint8_t c);

extern CircularBuffer_t UART1_rxBuffer;
extern CircularBuffer_t UART1_txBuffer;

// Make sure SDCC can find the interrupt
void UART1_ISR(void) __interrupt (INT_NO_UART1);
