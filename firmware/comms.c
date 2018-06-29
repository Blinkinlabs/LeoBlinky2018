#include "uart0_int.h"
#include "uart1_int.h"
#include "comms.h"
#include "leoblinky2018.h"
#include "circular_buffer.h"

// Commands:
// Command         size buf byte1            byte 2              byte 3
// LEFT_GEOMETRY    3   [0x01] [ledsToLeft]     [lettersToLeft]     [brightness]
// RIGHT_GEOMETRY   3   [0x02] [ledsToRight]    [lettersToRight]
// UPDATE           4   [0x03] [pattern]        [frameH]            [frameL]

#define LEFT_GEOMETRY_HEADER    0x01
#define RIGHT_GEOMETRY_HEADER   0x02
#define UPDATE_HEADER           0x03

void sendGeometryLeft() {
    // UART1 on left
    UART1_buf_write(RIGHT_GEOMETRY_HEADER);
    UART1_buf_write(ledsToRight + LED_COUNT);
    UART1_buf_write(lettersToRight + LETTER_COUNT);
}


void sendGeometryRight() {
    // UART0 on right
    UART0_buf_write(LEFT_GEOMETRY_HEADER);
    UART0_buf_write(ledsToLeft + LED_COUNT);
    UART0_buf_write(lettersToLeft + LETTER_COUNT);
    UART0_buf_write(brightness);
}

void sendUpdateRight() {
    // UART0 on right
    UART0_buf_write(UPDATE_HEADER);
    UART0_buf_write(pattern);
    UART0_buf_write((frame >> 8) & 0xFF);
    UART0_buf_write(frame);
}

void receiveLeft() {
    uint8_t c;
    uint8_t bufferSize;

    if(cbuff_empty(UART1_rxBuffer))
        return;

#if rxTimeout
    // Check if we should dump the previous buffer
    const int rxLeftEventTime = time.elapsed();
    if((rxLeftCount > 0)
            && (rxLeftEventTime - lastRxLeftEventTime) > SERIAL_TIMEOUT_MS) {
        qDebug() << "Timeout, Dumping bufffer";
        rxLeftCount = 0;
    }
    lastRxLeftEventTime = rxLeftEventTime;
#endif

    c = cbuff_peek(UART1_rxBuffer);
    bufferSize = cbuff_size(UART1_rxBuffer);

    if(c == LEFT_GEOMETRY_HEADER) {
        if(bufferSize == 4) {
//            qDebug() << "Got left geometry buf";

//            const uint8_t ledsToLeft = rxLeftBytes[1];
//            const uint8_t lettersToLeft = rxLeftBytes[2];
//            const uint8_t brightness = rxLeftBytes[3];
//
//            rxLeftGeometry(ledsToLeft, lettersToLeft, brightness);
//
//            rxLeftCount = 0;

            UART1_buf_read(&c);
            UART1_buf_read(&ledsToLeft);
            UART1_buf_read(&lettersToLeft);
            UART1_buf_read(&c);

            if(c != brightness) {
                brightness = c;
                brightnessChanged = true;
            }


            ttlLeft = 4;
        }
    }

    else if(c == UPDATE_HEADER) {
        if(bufferSize == 4) {
//            qDebug() << "Got left update buf";

//            const uint8_t pattern = rxLeftBytes[1];
//            const uint16_t frame = (rxLeftBytes[2] << 8) | rxLeftBytes[3];
//
//            rxFrame(pattern, frame);
//
//            rxLeftCount = 0;

            UART1_buf_read(&c);
            UART1_buf_read(&pattern);
            UART1_buf_read(((uint8_t*)&frame)+1);
            UART1_buf_read(((uint8_t*)&frame)+0);
            frameReady = true;
        }
    }

    else {
        //rxLeftCount = 0;
        while(UART1_buf_read(&c));
    }
}

void receiveRight() {
    uint8_t c;
    uint8_t bufferSize;


    if(cbuff_empty(UART0_rxBuffer))
        return;

#if rxTimeout
    // Check if we should dump the previous buffer
    const int rxLeftEventTime = time.elapsed();
    if((rxLeftCount > 0)
            && (rxLeftEventTime - lastRxLeftEventTime) > SERIAL_TIMEOUT_MS) {
        qDebug() << "Timeout, Dumping bufffer";
        rxLeftCount = 0;
    }
    lastRxLeftEventTime = rxLeftEventTime;
#endif

    c = cbuff_peek(UART0_rxBuffer);
    bufferSize = cbuff_size(UART0_rxBuffer);

    if(c == RIGHT_GEOMETRY_HEADER) {
        if(bufferSize == 3) {
//            qDebug() << "Got left geometry buf";

//            const uint8_t ledsToLeft = rxLeftBytes[1];
//            const uint8_t lettersToLeft = rxLeftBytes[2];
//            const uint8_t brightness = rxLeftBytes[3];
//
//            rxLeftGeometry(ledsToLeft, lettersToLeft, brightness);
//
//            rxLeftCount = 0;

            UART0_buf_read(&c);
            UART0_buf_read(&ledsToRight);
            UART0_buf_read(&lettersToRight);
            ttlRight = 4;
        }
    }

    else {
        //rxLeftCount = 0;
        while(UART0_buf_read(&c));
    }
}
