#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    uint8_t* const array;
    uint8_t readIndex;
    uint8_t writeIndex;
    const uint8_t maxBufferLength;
} CircularBuffer_t;

//extern uint8_t size(CircularBuffer_t *buf);
//extern bool empty(CircularBuffer_t *buf);
//extern bool full(CircularBuffer_t *buf);
//extern uint8_t mask(CircularBuffer_t *buf, uint8_t val);
//extern bool push(CircularBuffer_t *buf, uint8_t data);
//extern bool pop(CircularBuffer_t *buf, uint8_t *data);
//extern bool peek(CircularBuffer_t *buf, uint8_t *data);

#define cbuff_size(buf)       ((uint8_t)(buf.writeIndex - buf.readIndex))
#define cbuff_empty(buf)      (buf.readIndex == buf.writeIndex)
#define cbuff_full(buf)       (cbuff_size(buf) == buf.maxBufferLength)
#define cbuff_mask(buf, val)  (val & (buf.maxBufferLength - 1))
#define cbuff_reset(buf)      (buf.readIndex = buf.writeIndex = 0)

#define cbuff_push(buf, data) (buf.array[cbuff_mask(buf, buf.writeIndex++)] = data)
#define cbuff_pop(buf)        (buf.array[cbuff_mask(buf, buf.readIndex++)])
#define cbuff_peek(buf)       (buf.array[cbuff_mask(buf, buf.readIndex)])
