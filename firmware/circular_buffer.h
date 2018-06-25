#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t* const array;
    uint8_t readIndex;
    uint8_t writeIndex;
    const uint8_t maxBufferLength;
} CircularBuffer_t;

extern uint8_t size(CircularBuffer_t *buf);

extern bool empty(CircularBuffer_t *buf);

extern bool full(CircularBuffer_t *buf);

extern uint8_t mask(CircularBuffer_t *buf, uint8_t val);

extern bool push(CircularBuffer_t *buf, uint8_t data);

extern bool pop(CircularBuffer_t *buf, uint8_t *data);
