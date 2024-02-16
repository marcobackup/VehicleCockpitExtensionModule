#include "senderhandler.h"
#include <QDebug>
#include "core/controller/settings.h"
#include "core/uarthandler.h"

SenderHandler::SenderHandler(UartHandler *uartHandler, Settings *settings, QObject *parent)
    : QObject{parent}
    , uartHandler(uartHandler)
    , settings(settings)
{
    connect(settings, &Settings::themeChanged, this, &SenderHandler::handleEcmStatus);
    connect(settings, &Settings::languageChanged, this, &SenderHandler::handleEcmStatus);
    connect(settings, &Settings::audioStatusChanged, this, &SenderHandler::handleEcmStatus);
}

void SenderHandler::handleEnvironmentLight()
{
    QString payload = QString("eeprom#environmentLight#write#%1,%d,%d").arg(
                QString::number(settings->ambientLightSource()),
                QString::number(settings->ambientLightLRSeatLevel()),
                QString::number(settings->ambientLightRRSeatLevel()));
    uartHandler->send(payload.toUtf8());
}

void SenderHandler::handleEcmStatus()
{
    QString payload = QString("eeprom#ecmStatus#write#%1,%2,%3\n").arg(
                QString::number(settings->theme()),
                QString::number(settings->language()),
                QString::number(settings->audioStatus()));
    uartHandler->send(payload.toUtf8());
}

