#include <ch554.h>
#include <stdint.h>
#include <stdbool.h>

#include "uart1_int.h"


bool UART1_txActive;    // True while data is being sent

uint8_t UART1_rxBufferArray[UART1_RX_LEN];
uint8_t UART1_txBufferArray[UART1_TX_LEN];


CircularBuffer_t UART1_rxBuffer = {
    UART1_rxBufferArray,
    0,
    0,
    UART1_RX_LEN
};

CircularBuffer_t UART1_txBuffer = {
    UART1_txBufferArray,
    0,
    0,
    UART1_TX_LEN
};


// Configure UART1 for an interrupt-based circular buffer mode
void UART1_buf_init() {
    UART1_txActive = false;

    IE_UART1 = 1;     // Enable UART1 interrupts
    EA = 1;
}

void UART1_ISR(void) __interrupt (INT_NO_UART1) {
    // Handle an RX interrupt
    if(U1RI) {
        cbuff_push(UART1_rxBuffer, SBUF1);
        U1RI = 0;
    }
    // Handle a TX interrupt
    if(U1TI) {
        U1TI = 0;
	if(!cbuff_empty(UART1_txBuffer))
	    SBUF1 = cbuff_pop(UART1_txBuffer);
        else
            UART1_txActive = false;
    }
}

bool UART1_buf_read(uint8_t *c) {
    if(cbuff_empty(UART1_rxBuffer))
        return false;

    IE_UART1 = 0;
    *c = cbuff_pop(UART1_rxBuffer);
    IE_UART1 = 1;

    return true;
}

bool UART1_buf_write(const uint8_t c) {
    // If TX is busy, put it in the buffer,
    if (UART1_txActive) {
	    if(cbuff_full(UART1_txBuffer))
	        return false;

        IE_UART1 = 0;
        cbuff_push(UART1_txBuffer, c);
        IE_UART1 = 1;
    }
    // otherwise send it directly
    else {
        UART1_txActive = true;
        SBUF1 = c;
    }

    return true;
}
