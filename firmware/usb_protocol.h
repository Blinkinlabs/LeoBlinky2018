/*
 * CRC-checked serial packet protocol
 *
 * Copyright (c) 2014 Matt Mets
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef _PROTOCOL_h
#define _PROTOCOL_h

#include <stdint.h>
#include <stdbool.h>

// TODO: Need 256 bytes for a flash page.
#define MAX_DATA_LENGTH     270  // Maximum length of the data packet we can receive (up to 65534)

#define MODE_HEADER0        0x0     // Expecting the first header byte
#define MODE_HEADER1        0x1     // Expecting the second header byte
#define MODE_LENGTH0        0x2     // Expecting the high byte of the packet length
#define MODE_LENGTH1        0x3     // Expecting the low byte of the packet length
#define MODE_PAYLOAD        0x4
#define MODE_CRC            0x5
#define MODE_PAYLOAD_READY  0x6

#define HEADER0             0xde
#define HEADER1             0xad

// AnalogLED protocol decoder. Expects frames of data that look like this:
// [header (2 bytes)][length (2 bytes)][payload (length bytes)][ibutton crc (1 byte)]

extern void usb_protocol_reset();       // Reset the packet processor state machine

// Read a byte into the packet processor, and handle it as possible.
// @param data Data byte to read in
// @return true if a payload is ready to read
extern bool usb_protocol_parseByte(uint8_t data);


// Returns true if a payload is ready.
// The payload is available in
bool usb_protocol_payloadReady();

extern __xdata uint8_t usb_protocol_payloadData[MAX_DATA_LENGTH];    ///< Data received in this packet
extern __xdata uint16_t usb_protocol_payloadLength;                  ///< Number of bytes received for this packet

#endif
