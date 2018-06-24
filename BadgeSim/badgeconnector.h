#ifndef BADGECONNETOR_H
#define BADGECONNETOR_H

#include <QCheckBox>
#include "badge.h"

class BadgeConnector : public QCheckBox
{
public:
    BadgeConnector(Badge *leftBadge, Badge* rightBadge, QWidget *parent);

public slots:
    void onStateChanged(int arg1);

private:
    Badge *leftBadge;
    Badge *rightBadge;
};

#endif // BADGECONNETOR_H
