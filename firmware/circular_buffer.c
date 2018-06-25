#include "circular_buffer.h"

// https://www.snellman.net/blog/archive/2016-12-13-ring-buffers/

uint8_t size(CircularBuffer_t *buf) {
    return (buf->writeIndex - buf->readIndex);
}

bool empty(CircularBuffer_t *buf) {
    return (buf->readIndex == buf->writeIndex);
}

bool full(CircularBuffer_t *buf) {
    return size(buf) == buf->maxBufferLength;
}

uint8_t mask(CircularBuffer_t *buf, uint8_t val) {
    return val & (buf->maxBufferLength - 1);
}

bool push(CircularBuffer_t *buf, uint8_t data) {
    if(full(buf))
        return false;

    buf->array[mask(buf, buf->writeIndex++)] = data;
    return true;
}

bool pop(CircularBuffer_t *buf, uint8_t *data) {
    if(empty(buf))
        return false;

    *data = buf->array[mask(buf, buf->readIndex++)];
    return true;
}
