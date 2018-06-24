#include "badge.h"
#include <QDebug>
#include <QPainter>

#define TTL_START_COUNT 5

#define BORDER_SPACING 50
#define LED_SPACING_X 20
#define LED_SPACING_Y 60

// Commands:
// Command         size header byte1            byte 2              byte 3
// LEFT_GEOMETRY    3   [0x01] [ledsToLeft]     [lettersToLeft]     [brightness]
// RIGHT_GEOMETRY   3   [0x02] [ledsToRight]    [lettersToRight]
// UPDATE           4   [0x03] [pattern]        [frameH]            [frameL]

#define LEFT_GEOMETRY_HEADER    0x01
#define RIGHT_GEOMETRY_HEADER   0x02
#define UPDATE_HEADER           0x03

Badge::Badge(QString name, int ledCount, QWidget *parent) :
    QWidget(parent),
    name(name),
    ledCount(ledCount),
    ledsToLeft(0),
    lettersToLeft(0),
    ttlLeft(0),
    ledsToRight(0),
    lettersToRight(0),
    ttlRight(0),
    pattern(1),
    frame(0),
    brightness(255)
{
    setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    setMinimumSize(2*BORDER_SPACING+ledCount*LED_SPACING_X,
                   2*BORDER_SPACING+LED_SPACING_Y + LED_SPACING_X);

    letterCount = name.size();

    for(int count = 0; count < ledCount; count++)
        locations.push_back(QPoint((count+.5)*LED_SPACING_X, LED_SPACING_X/2));

    for(int count = ledCount-1; count >= 0; count--)
        locations.push_back(QPoint((count+.5)*LED_SPACING_X, LED_SPACING_Y+LED_SPACING_X/2));

    for(int count = 0; count < locations.size(); count++)
        colors.push_back(QColor(0,0,0));

    connect(&tickTimer, &QTimer::timeout,
            this, &Badge::tick);

    connect(&frameTimer, &QTimer::timeout,
            this, &Badge::nextFrame);

    tickTimer.start(1000);
    frameTimer.start(1000/30);  // Update at 30 fps
}

void Badge::dumpState()
{
    qDebug() << "name:" << name
             << "ledCount:" << ledCount
             << "ledsToLeft:" << ledsToLeft
             << "ledsToLeftTTL:" << ttlLeft
             << "ledsToRight:" << ledsToRight
             << "ledsToRightTTL:" << ttlRight;
}

void Badge::paintEvent(QPaintEvent * /*event*/)
{
    QPainter painter(this);

    painter.fillRect(this->rect(), Qt::white);
    painter.setRenderHint(QPainter::Antialiasing, true);

    painter.drawText(5,this->height()/2-15, QString("%1").arg(ledsToLeft));
    painter.drawText(this->width()-20,this->height()/2-15, QString("%2").arg(ledsToRight));

    painter.drawText(5,this->height()/2, QString("%1").arg(lettersToLeft));
    painter.drawText(this->width()-20,this->height()/2, QString("%2").arg(lettersToRight));

    painter.drawText(5,this->height()/2+15, QString("%1").arg(ttlLeft));
    painter.drawText(this->width()-20,this->height()/2+15, QString("%2").arg(ttlRight));

    if(isMaster())
        painter.drawText(5,15,"Master");
    else
        painter.drawText(5,15,"Receiver");

    painter.drawText(5,this->height()-15,QString("Pattern %1, Frame %2, Brightness %3")
                     .arg(pattern)
                     .arg(frame)
                     .arg(brightness));

    {
        painter.save();
        painter.translate(BORDER_SPACING,BORDER_SPACING);

        painter.fillRect(0,0,LED_SPACING_X*ledCount, LED_SPACING_Y+LED_SPACING_X,QColor(252,23,218));
        painter.drawRect(0,0,LED_SPACING_X*ledCount, LED_SPACING_Y+LED_SPACING_X);

        painter.setFont(QFont("Disorient 2017 Dots",LED_SPACING_Y/1.8));
        painter.drawText(LED_SPACING_X/4,LED_SPACING_Y,name);

        for(int i = 0; i < locations.size(); i++) {
            painter.setBrush(colors.at(i));
            painter.drawEllipse(locations.at(i),5,5);
        }

        painter.restore();
    }



}

void Badge::tick()
{
    if(ttlLeft > 0) {
        ttlLeft--;

        if(ttlLeft == 0)
            ledsToLeft = 0;
    }

    if(ttlRight > 0) {
        ttlRight--;

        if(ttlRight == 0)
            ledsToRight = 0;
    }

    sendGeometryLeft();
    sendGeometryRight();


//    qDebug() << name << "tick";
//    dumpState();
    update();
}

void Badge::nextFrame()
{
    if(!isMaster())
        return;

    if(pattern == 0) {
        frame++;
        if(frame >= (ledCount + ledsToRight)*5)
            frame = 0;
    }
    else if(pattern == 1) {
        frame++;
        if(frame >= (ledCount + ledsToRight)*2)
            frame = 0;
    }

//    emit(txFrame(frame));
    sendUpdateRight();

    drawFrame();
}

void Badge::rxFrame(uint8_t pattern, uint16_t frame)
{
    this->pattern = pattern;
    this->frame = frame;

//    emit(txFrame(frame));
    sendUpdateRight();

    drawFrame();
}

void Badge::drawFrame() {
    for(int i = 0; i < locations.size(); i++) {

        int brightness = 0;

        if(pattern == 0) {
            if((locations.at(i).x()/LED_SPACING_X + ledsToLeft) == (frame/5))
                brightness = 255;
            else
                brightness = 0;
        }
        else if(pattern == 1) {
            brightness = 255/(.0001 + abs(locations.at(i).x()/LED_SPACING_X + ledsToLeft - (frame/2)));
            if(brightness > 255)
                brightness = 255;
        }

        colors[i] = QColor(brightness,brightness,brightness);
    }

    update();
}

void Badge::sendGeometryLeft()
{
    emit(txLeftByte(RIGHT_GEOMETRY_HEADER));
    emit(txLeftByte(ledsToRight + ledCount));
    emit(txLeftByte(lettersToRight + letterCount));
}

void Badge::sendGeometryRight()
{
    emit(txRightByte(LEFT_GEOMETRY_HEADER));
    emit(txRightByte(ledsToLeft + ledCount));
    emit(txRightByte(lettersToLeft + letterCount));
    emit(txRightByte(brightness));
}

void Badge::sendUpdateRight()
{
    emit(txRightByte(UPDATE_HEADER));
    emit(txRightByte(pattern));
    emit(txRightByte((frame>>8) & 0xFF));
    emit(txRightByte((frame>>0) & 0xFF));
}

void Badge::rxLeft(uint8_t ledsToLeft, uint8_t lettersToLeft, uint8_t brightness)
{
    ttlLeft = TTL_START_COUNT;

    if(this->ledsToLeft != ledsToLeft
            || this->lettersToLeft != lettersToLeft
            || this->brightness != brightness) {
        this->ledsToLeft = ledsToLeft;
        this->lettersToLeft = lettersToLeft;
        this->brightness = brightness;

        sendGeometryRight();

        update();
    }
}

void Badge::rxRight(uint8_t ledsToRight, uint8_t lettersToRight)
{
    ttlRight = TTL_START_COUNT;

    if((this->ledsToRight != ledsToRight)
            || (this->lettersToRight != lettersToRight)) {
        this->ledsToRight = ledsToRight;
        this->lettersToRight = lettersToRight;

        sendGeometryLeft();

        update();
    }
}

void Badge::rxLeftByte(uint8_t byte)
{
    rxLeftBytes.push_back(byte);

    if((rxLeftBytes.front() == LEFT_GEOMETRY_HEADER) && (rxLeftBytes.length() == 4)) {
        qDebug() << "Got left geometry header";
        rxLeftBytes.pop_front();
        uint8_t ledsToLeft = rxLeftBytes.takeFirst();
        uint8_t lettersToLeft = rxLeftBytes.takeFirst();
        uint8_t brightness = rxLeftBytes.takeFirst();

        rxLeft(ledsToLeft, lettersToLeft, brightness);
    }
    else if((rxLeftBytes.front() == UPDATE_HEADER) && (rxLeftBytes.length() == 4)) {
        qDebug() << "Got left update header";
        rxLeftBytes.pop_front();
        uint8_t pattern = rxLeftBytes.takeFirst();
        uint16_t frame = rxLeftBytes.takeFirst() << 8;
        frame |= rxLeftBytes.takeFirst();

        rxFrame(pattern, frame);
    }

}

void Badge::rxRightByte(uint8_t byte)
{
    rxRightBytes.push_back(byte);

    if((rxRightBytes.front() == RIGHT_GEOMETRY_HEADER) && (rxRightBytes.length() == 3)) {
        qDebug() << "Got right geometry header";
        rxRightBytes.pop_front();
        uint8_t ledsToRight = rxRightBytes.takeFirst();
        uint8_t lettersToRight = rxRightBytes.takeFirst();

        rxRight(ledsToRight, lettersToRight);
    }
}

void Badge::clickBrightnessButton()
{
    brightness = (brightness * 2)%256;
    if(brightness == 0)
        brightness = 10;
}

bool Badge::isMaster() const
{
    return (ledsToLeft == 0);
}
