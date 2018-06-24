#include "paritybyte.h"

ParityByte::ParityByte(uint8_t data) :
    data(data)
{
    parity = computeParity(data);
}

bool ParityByte::checkParity() {
    return computeParity(data) == parity;
}

bool ParityByte::computeParity(uint8_t data) {
    return (  ((data >> 7) & 0x01)
             ^((data >> 6) & 0x01)
             ^((data >> 5) & 0x01)
             ^((data >> 4) & 0x01)
             ^((data >> 3) & 0x01)
             ^((data >> 2) & 0x01)
             ^((data >> 1) & 0x01)
             ^((data >> 0) & 0x01));
}
