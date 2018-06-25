#include "uart0_int.h"
#include "uart1_int.h"
#include "comms.h"
#include "leoblinky2018.h"

// Commands:
// Command         size header byte1            byte 2              byte 3
// LEFT_GEOMETRY    3   [0x01] [ledsToLeft]     [lettersToLeft]     [brightness]
// RIGHT_GEOMETRY   3   [0x02] [ledsToRight]    [lettersToRight]
// UPDATE           4   [0x03] [pattern]        [frameH]            [frameL]

#define LEFT_GEOMETRY_HEADER    0x01
#define RIGHT_GEOMETRY_HEADER   0x02
#define UPDATE_HEADER           0x03

void sendGeometryLeft() {
    // UART1 on left
    UART1_buf_write(RIGHT_GEOMETRY_HEADER);
    UART1_buf_write(lettersToRight + LED_COUNT);
    UART1_buf_write(lettersToRight + LETTER_COUNT);
}


void sendGeometryRight() {
    // UART0 on right
    UART0_buf_write(LEFT_GEOMETRY_HEADER);
    UART0_buf_write(lettersToLeft + LED_COUNT);
    UART0_buf_write(lettersToLeft + LETTER_COUNT);
    UART0_buf_write(brightness);
}
