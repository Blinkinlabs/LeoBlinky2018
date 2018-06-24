#include "badgeconnector.h"

#define LOSS_RATE               0.001
#define SINGLE_BIT_ERROR_RATE   0.01
#define DUAL_BIT_ERROR_RATE     0.001

BadgeConnector::BadgeConnector(Badge *leftBadge, Badge *rightBadge, QWidget *parent) :
    QCheckBox(parent),
    leftBadge(leftBadge),
    rightBadge(rightBadge),
    rightToLeft(1, SINGLE_BIT_ERROR_RATE, DUAL_BIT_ERROR_RATE, this),
    leftToRight(1, SINGLE_BIT_ERROR_RATE, DUAL_BIT_ERROR_RATE, this)
{
    connect(this, &BadgeConnector::stateChanged,
            this, &BadgeConnector::onStateChanged);

    connect(leftBadge, &Badge::txRight,
            &leftToRight, &NoiseStream::rx);
    connect(&leftToRight, &NoiseStream::tx,
            rightBadge, &Badge::rxLeft);

    connect(rightBadge, &Badge::txLeft,
            &rightToLeft, &NoiseStream::rx);
    connect(&rightToLeft, &NoiseStream::tx,
            leftBadge, &Badge::rxRight);
}

void BadgeConnector::onStateChanged(int arg1)
{
    if(arg1 == 0) {
        leftToRight.lossRate = 1;
        rightToLeft.lossRate = 1;
    }
    else {
        leftToRight.lossRate = LOSS_RATE;
        rightToLeft.lossRate = LOSS_RATE;
    }
}
