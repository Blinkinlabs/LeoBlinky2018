#include "circular_buffer.h"

// https://www.snellman.net/blog/archive/2016-12-13-ring-buffers/

#if 0
uint8_t size(CircularBuffer_t *buf) {
    return (buf->writeIndex - buf->readIndex);
}

bool empty(CircularBuffer_t *buf) {
    return (buf->readIndex == buf->writeIndex);
}

bool full(CircularBuffer_t *buf) {
    return cbuff_size(buf) == buf->maxBufferLength;
}

uint8_t mask(CircularBuffer_t *buf, uint8_t val) {
    return val & (buf->maxBufferLength - 1);
}

bool push(CircularBuffer_t *buf, uint8_t data) {
    if(cbuff_full(buf))
        return false;

    buf->array[cbuff_mask(buf, buf->writeIndex++)] = data;
    return true;
}

bool pop(CircularBuffer_t *buf, uint8_t *data) {
    if(cbuff_empty(buf))
        return false;

    *data = buf->array[cbuff_mask(buf, buf->readIndex++)];
    return true;
}

bool peek(CircularBuffer_t *buf, uint8_t *data) {
    if(cbuff_empty(buf))
        return false;

    *data = buf->array[cbuff_mask(buf, buf->readIndex)];
    return true;
}
#endif
