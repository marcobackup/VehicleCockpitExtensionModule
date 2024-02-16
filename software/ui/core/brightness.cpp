#include "brightness.h"
#include <QDebug>

Brightness::Brightness(QObject *parent)
    : QObject{parent}
    , brightnessFile(*new QFile("/sys/class/backlight/10-0045/brightness"))
    , powerFile(*new QFile("/sys/class/backlight/10-0045/bl_power"))
{
    brightnessFile.setFileName("/sys/class/backlight/10-0045/brightness");
    powerFile.setFileName("/sys/class/backlight/10-0045/bl_power");
}

Brightness::~Brightness()
{
    delete &brightnessFile;
    delete &powerFile;
}

bool Brightness::openFile(QFile &file) {
    if(!file.open(QIODevice::ReadWrite))
        return false;
    return true;
}

QByteArray Brightness::getBrightness() {
    if(!Brightness::openFile(brightnessFile))
        return 0;
    return brightnessFile.readAll();
}

void Brightness::setBrightness(int brightness) {
    QByteArray data = QByteArray::number(brightness);
    if(!Brightness::openFile(brightnessFile))
        return;
    brightnessFile.write(data.constData(), data.size());
    brightnessFile.close();
}

void Brightness::powerOff() {
    QByteArray data = QByteArray::number(1);
    if(!Brightness::openFile(brightnessFile))
        return;
    brightnessFile.write(data.constData(), data.size());
    brightnessFile.close();
}

void Brightness::powerOn() {
    QByteArray data = QByteArray::number(0);
    if(!Brightness::openFile(brightnessFile))
        return;
    brightnessFile.write(data.constData(), data.size());
    brightnessFile.close();
}
