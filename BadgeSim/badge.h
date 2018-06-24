#ifndef BADGE_H
#define BADGE_H

#include <QWidget>
#include <QTimer>
#include <QColor>

class Badge: public QWidget
{
Q_OBJECT

public:
    Badge(QString name, int ledCount, QWidget *parent);

    void dumpState();

    void paintEvent(QPaintEvent *event);

signals:
    void txRightByte(uint8_t byte);
    void txLeftByte(uint8_t byte);

public slots:
    void tick();
    void nextFrame();

    void rxLeftByte(uint8_t byte);
    void rxRightByte(uint8_t byte);

    void clickBrightnessButton();

private:
    bool isMaster() const;
    void drawFrame();

    void sendGeometryLeft();
    void sendGeometryRight();
    void sendUpdateRight();

    void rxLeft(uint8_t ledsToLeft, uint8_t lettersToLeft, uint8_t brightness);
    void rxRight(uint8_t ledsToRight, uint8_t lettersToLeft);
    void rxFrame(uint8_t pattern, uint16_t frame);

    QTimer tickTimer;
    QTimer frameTimer;

//    QTimer txTimer;     // Used to simulate slow baud rate?

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

    QList<uint8_t> rxRightBytes;
    QList<uint8_t> rxLeftBytes;
};

#endif // BADGE_H
