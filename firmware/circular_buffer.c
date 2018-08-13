#include "circular_buffer.h"


void cbuff_push(CircularBuffer_t *buff, uint8_t data)
{
//    Receive_Uart_Buf[Uart_Input_Point++] = byte;
//    UartByteCount++;                    //Current buffer remaining bytes to be fetched
//    if(Uart_Input_Point>=UART_REV_LEN)
//        Uart_Input_Point = 0;           //Write pointer

    buff->array[buff->writeIndex++] = data;

    if(buff->writeIndex >= buff->bufferSize)
        buff->writeIndex = 0;

    buff->byteCount++;
}

uint8_t cbuff_pop(CircularBuffer_t *buff)
{
    uint8_t data;

    data = buff->array[buff->readIndex++];

    if(buff->readIndex >= buff->bufferSize)
        buff->readIndex = 0;

    buff->byteCount--;

    return data;
}

//uint8_t cbuff_peek(CircularBuffer_t *buff)
//{
//    return buff->array[buff->readIndex];
//}

//void cbuff_reset(CircularBuffer_t *buff)
//{
//    buff->readIndex = 0;
//    buff->writeIndex = 0;
//    buff->byteCount = 0;
//}
