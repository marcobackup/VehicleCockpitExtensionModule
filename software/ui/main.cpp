#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include "core/alertqueue.h"
#include "core/uarthandler.h"
#include "core/can/messagehandler.h"
#include "core/senderhandler.h"
#include "core/controller.h"
#include "core/controller/gauge.h"
#include "core/controller/carparameter.h"
#include "core/controller/trip.h"
#include "core/controller/topbar.h"
#include "core/controller/bottombar.h"
#include "core/controller/settings.h"
#include "core/soundhandler.h"
#include "core/brightness.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);

    // display brightness handler
    Brightness brightnessHandler;

    // sound handler
    SoundHandler soundHandler;

    // alert queue handler
    AlertQueue alertQueueHandler;

    // controllers
    Gauge gaugeController;
    CarParameter carParameterController;
    Trip tripController;
    TopBar topBarController(&brightnessHandler);
    BottomBar bottomBarController;
    Settings settingsController;

    Controller controller(&gaugeController, &carParameterController, &tripController, &topBarController, &bottomBarController, &settingsController);

    // uart handler instance
    UartHandler uartHandler;

    // sender handler instance
    SenderHandler senderHandler(&uartHandler, &settingsController);

    // message handler instance
    MessageHandler messageHandler(&controller, &alertQueueHandler);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);

    bool uiLoaded = false;

    // set qt object as property
    QQmlContext *context(engine.rootContext());
    context->setContextProperty("gaugeController", (QObject *) &gaugeController);
    context->setContextProperty("carParameterController", (QObject *) &carParameterController);
    context->setContextProperty("tripController", (QObject *) &tripController);
    context->setContextProperty("topBarController", (QObject *) &topBarController);
    context->setContextProperty("bottomBarController", (QObject *) &bottomBarController);
    context->setContextProperty("settingsController", (QObject *) &settingsController);
    context->setContextProperty("alertQueueHandler", (QObject *) &alertQueueHandler);

    // listen to incoming uart data
    QObject::connect(&uartHandler, &UartHandler::dataReceived, [&messageHandler](UartHandler::rxMessage data) {
        messageHandler.handleMessageData(data);
    });

    // set brightness to max level
    brightnessHandler.setBrightness(255);

    // listen to incoming settings ecm status data
    QObject::connect(&uartHandler, &UartHandler::settingsEcmStatusReceived, [&settingsController, &soundHandler, &uiLoaded](UartHandler::settingsEcmStatusStruct data) {
        settingsController.setTheme(data.theme);
        if(!uiLoaded) {
            uiLoaded = true;
            emit settingsController.settingsConfigLoaded();

            // start up chime effect
            soundHandler.playWarningChimeSoundEffect(2);
        }
    });

    // start UI
    engine.load(url);

    return app.exec();
}
