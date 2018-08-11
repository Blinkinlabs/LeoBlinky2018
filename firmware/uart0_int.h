#pragma once

#include <ch554.h>
#include <stdint.h>
#include <stdbool.h>
#include "circular_buffer.h"

// Length of the RX buffer. Must be a multiple of 2
#ifndef UART0_RX_LEN
#define UART0_RX_LEN 8
#endif

// Length of the TX buffer. Must be a multiple of 2
#ifndef UART0_TX_LEN
#define UART0_TX_LEN 4
#endif

// Initialize the circular buffer. Assumes that the
// UART was already configured for the correct operating
// mode and baud rate
void UART0_buf_init();

// Reset the receive buffer, clearing any data in it
void UART0_buf_reset_rx();

// Read from the circular buffer
// @param c Location to store the read data, if successful
// @return True if successful, false otherwise
bool UART0_buf_read(uint8_t *c);

// Write to the circular buffer
// @param c Data to write to the buffer
// @return True if successful, false otherwise
bool UART0_buf_write(const uint8_t c);

extern CircularBuffer_t UART0_rxBuffer;
extern CircularBuffer_t UART0_txBuffer;

// Make sure SDCC can find the interrupt
void UART0_ISR(void) __interrupt (INT_NO_UART0);
