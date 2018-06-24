#ifndef PARITYBYTE_H
#define PARITYBYTE_H

#include <stdint.h>

class ParityByte {
public:
    static bool computeParity(uint8_t data);

public:
    ParityByte(uint8_t data);
    bool checkParity();

    uint8_t data;
    bool parity;
};

#endif // PARITYBYTE_H
