#include "usb_protocol.h"

__xdata uint16_t m_expectedLength;                          ///< Number of bytes expected in the current packet
__xdata uint8_t m_mode;                                     ///< Current operational mode
__xdata uint8_t usb_protocol_payloadData[MAX_DATA_LENGTH];  ///< Data received in this packet
__xdata uint16_t usb_protocol_payloadLength;                ///< Number of bytes received for this packet
__xdata uint8_t m_crc;                                      ///< CRC calculated for this packet


//// add a new byte to the CRC
//void updateCRC(uint8_t data);

// store a new byte in the packet
void addByte(uint8_t data);

void addByte(uint8_t data) {
    usb_protocol_payloadData[usb_protocol_payloadLength++] = data;

//    updateCRC(data);
}

//void updateCRC(uint8_t data) {
//    uint8_t i;

//    m_crc = m_crc ^ data;
//    for (i = 0; i < 8; i++)
//    {
//        if(m_crc & 0x01) {
//            m_crc = (m_crc >> 1) ^ 0x8C;
//        }
//        else {
//            m_crc >>= 1;
//        }
//    }
//}

void usb_protocol_reset() {
    m_crc = 0;
    usb_protocol_payloadLength = 0;
    m_mode = MODE_HEADER0;
}

bool usb_protocol_parseByte(uint8_t data) {
    switch(m_mode) {
    case MODE_HEADER0:
    case MODE_PAYLOAD_READY: // If we get new data before a payload is handled, just start over.
        if(data == HEADER0) {
            usb_protocol_reset();
            m_mode = MODE_HEADER1;
//            updateCRC(data);
        }
        break;
    case MODE_HEADER1:
        if(data == HEADER1) {
            m_mode = MODE_LENGTH0;
//            updateCRC(data);
        }
        else
            usb_protocol_reset();
        break;
    case MODE_LENGTH0:
        m_mode = MODE_LENGTH1;
        m_expectedLength = data << 8;
//        updateCRC(data);
        break;
    case MODE_LENGTH1:
        m_mode = MODE_PAYLOAD;
        m_expectedLength |= data;
//        updateCRC(data);
        if (m_expectedLength >= MAX_DATA_LENGTH)
            usb_protocol_reset();
        break;
    case MODE_PAYLOAD:
        addByte(data);
        if(usb_protocol_payloadLength >= m_expectedLength) {  // TODO: why >= and not just ==?
            m_mode = MODE_CRC;
        }
        break;
    case MODE_CRC:
        //if(data == m_crc) {
        m_mode = MODE_PAYLOAD_READY;
        //}
        //else
        //  usb_protocol_reset();
        break;
    default:
        usb_protocol_reset();
    }

    return (m_mode == MODE_PAYLOAD_READY);
}

bool usb_protocol_payloadReady() {
    return (m_mode == MODE_PAYLOAD_READY);
}
