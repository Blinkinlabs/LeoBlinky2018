#include <ch554.h>

#include "uart0_int.h"
#include "circular_buffer.h"


bool UART0_txActive;    // True while data is being sent

uint8_t UART0_rxBufferArray[UART0_RX_LEN];
uint8_t UART0_txBufferArray[UART0_TX_LEN];

uint8_t UART0_ISR_tmp;

CircularBuffer_t UART0_rxBuffer = {
    UART0_rxBufferArray,
    0,
    0,
    UART0_RX_LEN
};

CircularBuffer_t UART0_txBuffer = {
    UART0_txBufferArray,
    0,
    0,
    UART0_TX_LEN
};


// Configure UART0 for an interrupt-based circular buffer mode
void UART0_buf_init() {
    UART0_txActive = false;

    ES = 1;     // Enable UART0 interrupts
    EA = 1;
}

void UART0_ISR(void) __interrupt (INT_NO_UART0) {
    if(RI) {
        // TODO: Error on overflow?
        UART0_ISR_tmp = SBUF;
        push(&UART0_rxBuffer, UART0_ISR_tmp);
        RI = 0;
    }
    if(TI) {
        TI = 0;
        if(pop(&UART0_txBuffer, &UART0_ISR_tmp))
            SBUF = UART0_ISR_tmp;
        else
            UART0_txActive = false;
    }
}

bool UART0_buf_read(uint8_t *c) {
    bool result;

    ES = 0;
    result = pop(&UART0_rxBuffer, c);
    ES = 1;

    return result;
}

bool UART0_buf_write(const uint8_t c) {
    bool result = true; 

    // If TX is busy, put it in the buffer,
    if (UART0_txActive) {
        ES = 0;
        result = push(&UART0_txBuffer, c);
        ES = 1;
    }
    // otherwise send it directly
    else {
        UART0_txActive = true;
        SBUF = c;
    }

    return result;
}
