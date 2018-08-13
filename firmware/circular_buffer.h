#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
    __idata uint8_t* const array;   //Serial receive buffer
    uint8_t writeIndex;             //Circular buffer write pointer, set to 0 on reset
    uint8_t readIndex;              //Circular buffer fetches the pointer, set to 0 on reset
    uint8_t byteCount;              //Current buffer remaining bytes to be fetched
    const uint8_t bufferSize;       // Size of the buffer

} CircularBuffer_t;

#define cbuff_reset(buff)       {buff.readIndex = buff.writeIndex = buff.byteCount = 0;}

#define cbuff_size(buff)        (buff.byteCount)
#define cbuff_empty(buff)       (buff.byteCount == 0)
#define cbuff_full(buff)        (buff.byteCount == buff.bufferSize)
#define cbuff_peek(buff)        (buff.array[buff.readIndex])

#define cbuff_push(buff, data) {                \
    buff.array[buff.writeIndex++] = data;       \
    if(buff.writeIndex >= buff.bufferSize)      \
        buff.writeIndex = 0;                    \
    buff.byteCount++;                           \
    }

#define cbuff_pop(buff, data) {                 \
    data = buff.array[buff.readIndex++];        \
    if(buff.readIndex >= buff.bufferSize)       \
        buff.readIndex = 0;                     \
    buff.byteCount--;                           \
    }

