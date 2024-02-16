#ifndef SENDERHANDLER_H
#define SENDERHANDLER_H

#include <QObject>
#include "core/controller/settings.h"
#include "core/uarthandler.h"

class SenderHandler : public QObject
{
public:
    explicit SenderHandler(UartHandler *uartHandler, Settings *settings, QObject *parent = nullptr);

private:
    UartHandler *uartHandler;
    Settings *settings;

signals:
    void handleEnvironmentLight();
    void handleEcmStatus();
};

#endif // SENDERHANDLER_H
