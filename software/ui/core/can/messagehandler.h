#ifndef MESSAGEHANDLER_H
#define MESSAGEHANDLER_H

#include <QObject>
#include "core/uarthandler.h"
#include "core/controller.h"
#include "core/alertqueue.h"

class MessageHandler {
private:
    Controller *controller;
    AlertQueue *alertQueue;

    // dynamic var
    bool iceOnRoadWarningStatus;
    bool lowFuelWarningStatus;
    bool highCoolantTemperatureWarningStatus;
    bool stopLightFailStatus;
    bool rearFogLightFailStatus;
    bool drlFailStatus;
    bool parkLightFailStatus;
    bool plateLightFailStatus;
    bool leftTurnLightFailStatus;
    bool rightTurnLightFailStatus;
    bool steeringWheelFailStatus;
public:
    MessageHandler(Controller *controller, AlertQueue *alertQueue);
    ~MessageHandler();
    void handleMessageData(UartHandler::rxMessage message);
};

#endif // MESSAGEHANDLER_H
