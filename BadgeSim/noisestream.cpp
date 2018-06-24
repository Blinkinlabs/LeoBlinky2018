#include "noisestream.h"

#include <QDebug>
#include <QRandomGenerator>

NoiseStream::NoiseStream(double lossRate, double bitErrorRate, double dualBitErrorRate, QObject *parent) :
    QObject(parent),
    lossRate(lossRate),
    bitErrorRate(bitErrorRate),
    dualBitErrorRate(dualBitErrorRate)
{

}

void NoiseStream::rx(ParityByte byte)
{
    int corruptedBits = 0;

    // First, simulate losing a byte entirely
    if(QRandomGenerator::global()->generateDouble() < lossRate) {
        qDebug() << "Dropping byte";
        return;
    }

    // Then test if the byte should have one corrupted bit
    if(QRandomGenerator::global()->generateDouble() < bitErrorRate) {
        corruptedBits = 1;
    }
    if(QRandomGenerator::global()->generateDouble() < dualBitErrorRate) {
        corruptedBits = 2;
    }


    for(int i = 0; i < corruptedBits; i++) {
        // If it is to be corrupted, xor it with one bit.
        const unsigned int corruptedBit = (QRandomGenerator::global()->generate())%9;

        qDebug() << "Corrupting bit: " << corruptedBit;

        if(corruptedBit == 8)
            byte.parity = !byte.parity;
        else
            byte.data = byte.data ^ (1<<corruptedBit);
    }


    emit(tx(byte));
}
