#ifndef BRIGHTNESS_H
#define BRIGHTNESS_H

#define MAX_BRIGHTNESS 255
#define MIN_BRIGHTNESS 0

#include <QObject>
#include <QFile>

class Brightness : public QObject
{
public:
    explicit Brightness(QObject *parent = nullptr);
    ~Brightness();

    bool openFile(QFile &file);
    QByteArray getBrightness();
    void setBrightness(int brightness);
    void powerOff();
    void powerOn();
private:
    QFile &brightnessFile;
    QFile &powerFile;
signals:

};

#endif // BRIGHTNESS_H
