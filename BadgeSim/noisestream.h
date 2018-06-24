#ifndef NOISESTREAM_H
#define NOISESTREAM_H

#include <QObject>
#include "paritybyte.h"

class NoiseStream : public QObject
{
    Q_OBJECT
public:
    explicit NoiseStream(double lossRate, double bitErrorRate, double dualBitErrorRate, QObject *parent = nullptr);

signals:
    void tx(ParityByte byte);

public slots:
    void rx(ParityByte byte);

public:
    double lossRate;
    double bitErrorRate;
    double dualBitErrorRate;
};

#endif // NOISESTREAM_H
