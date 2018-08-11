#pragma once

#include <stdint.h>
#include <stdbool.h>

typedef struct {
// Original circular buffer logic
//    __idata uint8_t* const array;
//    uint8_t readIndex;
//    uint8_t writeIndex;
//    const uint8_t maxBufferLength;

    __idata uint8_t* const array;   //Serial receive buffer
    uint8_t writeIndex;             //Circular buffer write pointer, set to 0 on reset
    uint8_t readIndex;              //Circular buffer fetches the pointer, set to 0 on reset
    uint8_t byteCount;              //Current buffer remaining bytes to be fetched
    const uint8_t bufferSize;       // Size of the buffer

} CircularBuffer_t;

// Original circular buffer logic
// see: https://www.snellman.net/blog/archive/2016-12-13-ring-buffers/

//#define cbuff_size(buf)       ((uint8_t)(buf.writeIndex - buf.readIndex))
//#define cbuff_empty(buf)      (buf.readIndex == buf.writeIndex)
//#define cbuff_full(buf)       (cbuff_size(buf) == buf.maxBufferLength)
//#define cbuff_mask(buf, val)  (val & (buf.maxBufferLength - 1))
//#define cbuff_reset(buf)      (buf.readIndex = buf.writeIndex = 0)

//#define cbuff_push(buf, data) (buf.array[cbuff_mask(buf, buf.writeIndex++)] = data)
//#define cbuff_pop(buf)        (buf.array[cbuff_mask(buf, buf.readIndex++)])
//#define cbuff_peek(buf)       (buf.array[cbuff_mask(buf, buf.readIndex)])


#define cbuff_size(buff)        (buff.byteCount)
#define cbuff_empty(buff)       (buff.byteCount == 0)
#define cbuff_full(buff)        (buff.byteCount == buff.bufferSize)
void cbuff_reset(CircularBuffer_t *buff);

void cbuff_push(CircularBuffer_t *buff, uint8_t data);
uint8_t cbuff_pop(CircularBuffer_t *buff);
uint8_t cbuff_peek(CircularBuffer_t *buff);
