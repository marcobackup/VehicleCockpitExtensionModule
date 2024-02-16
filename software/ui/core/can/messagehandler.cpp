#include "messagehandler.h"
#include "core/uarthandler.h"
#include "core/controller.h"
#include "core/alertqueue.h"

MessageHandler::MessageHandler(Controller *controller, AlertQueue *alertQueue)
    : controller(controller)
    , alertQueue(alertQueue) {

    // dynamic var
    bool iceOnRoadWarningStatus = false;
    bool lowFuelWarningStatus = false;
    bool highCoolantTemperatureWarningStatus = false;
    bool stopLightFailStatus = false;
    bool rearFogLightFailStatus = false;
    bool drlFailStatus = false;
    bool parkLightFailStatus = false;
    bool plateLightFailStatus = false;
    bool leftTurnLightFailStatus = false;
    bool rightTurnLightFailStatus = false;
    bool steeringWheelFailStatus = false;
}

MessageHandler::~MessageHandler() {
}

void MessageHandler::handleMessageData(UartHandler::rxMessage message) {
    /*
     * handle can message and
     * edit Q_OBJECT properties
     * or start tasks
     */
}
