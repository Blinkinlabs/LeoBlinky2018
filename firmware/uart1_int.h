#pragma once

#include <ch554.h>
#include <stdint.h>
#include <stdbool.h>
#include "circular_buffer.h"

// Length of the RX buffer
#ifndef UART1_RX_LEN
#define UART1_RX_LEN 8          // Can receive sendGeometryRight() and sendUpdateRight()
#endif

// Length of the TX buffer
#ifndef UART1_TX_LEN
#define UART1_TX_LEN 2          // only sends sendGeometryLeft() messages
#endif

// Initialize the circular buffer. Assumes that the
// UART was already configured for the correct operating
// mode and baud rate
void UART1_buf_init();

// Reset the receive buffer, clearing any data in it
void UART1_buf_reset_rx();

// Read from the circular buffer
// @param c Location to store the read data, if successful
// @return True if successful, false otherwise
bool UART1_buf_read(uint8_t *c);

// Write to the circular buffer
// @param c Data to write to the buffer
// @return True if successful, false otherwise
bool UART1_buf_write(const uint8_t c);

extern CircularBuffer_t UART1_rxBuffer;
extern CircularBuffer_t UART1_txBuffer;

// Make sure SDCC can find the interrupt
void UART1_ISR(void) __interrupt (INT_NO_UART1);
