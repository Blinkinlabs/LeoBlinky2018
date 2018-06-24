#ifndef BADGE_H
#define BADGE_H

#include <QWidget>
#include <QTimer>
#include <QColor>
#include <QTime>

#include "paritybyte.h"

#define SERIAL_BUFFER_LENGTH 4


class Badge: public QWidget
{
Q_OBJECT

public:
    Badge(QString name, int ledCount, QWidget *parent);

    void dumpState();

    void paintEvent(QPaintEvent *event);

signals:
    void txRight(ParityByte byte);
    void txLeft(ParityByte byte);

public slots:
    void tick();
    void nextFrame();

    void rxLeft(ParityByte byte);
    void rxRight(ParityByte byte);

    void clickBrightnessButton();

private:
    bool isMaster() const;
    void drawFrame();

    void sendGeometryLeft();
    void sendGeometryRight();
    void sendUpdateRight();

    void rxLeftGeometry(uint8_t ledsToLeft, uint8_t lettersToLeft, uint8_t brightness);
    void rxRightGeometry(uint8_t ledsToRight, uint8_t lettersToLeft);
    void rxFrame(uint8_t pattern, uint16_t frame);

    QTimer tickTimer;
    QTimer frameTimer;

    QTime time;

    QString name;
    int ledCount;
    int letterCount;

    int ledsToLeft;
    int lettersToLeft;
    int ttlLeft;

    int ledsToRight;
    int lettersToRight;
    int ttlRight;

    QList<QPoint> locations;
    QList<QColor> colors;

    // This should be in an animations class
    uint8_t pattern;
    uint16_t frame;
    uint8_t brightness;

    uint8_t rxLeftBytes[SERIAL_BUFFER_LENGTH];
    uint8_t rxLeftCount;
    int lastRxLeftEventTime;

    uint8_t rxRightBytes[SERIAL_BUFFER_LENGTH];
    uint8_t rxRightCount;
    int lastRxRightEventTime;
};

#endif // BADGE_H
