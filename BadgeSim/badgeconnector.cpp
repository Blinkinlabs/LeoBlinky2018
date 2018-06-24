#include "badgeconnector.h"

BadgeConnector::BadgeConnector(Badge *leftBadge, Badge *rightBadge, QWidget *parent) :
    QCheckBox(parent),
    leftBadge(leftBadge),
    rightBadge(rightBadge)
{
    connect(this, &BadgeConnector::stateChanged,
            this, &BadgeConnector::onStateChanged);
}

void BadgeConnector::onStateChanged(int arg1)
{
    if(arg1 == 0) {
        disconnect(leftBadge, &Badge::txRightByte,
                   rightBadge, &Badge::rxLeftByte);
        disconnect(rightBadge, &Badge::txLeftByte,
                   leftBadge, &Badge::rxRightByte);
    }
    else {
        connect(leftBadge, &Badge::txRightByte,
                   rightBadge, &Badge::rxLeftByte);
        connect(rightBadge, &Badge::txLeftByte,
                   leftBadge, &Badge::rxRightByte);
    }
}
