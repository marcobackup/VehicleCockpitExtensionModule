QT += quick
QT += widgets
QT += serialport
QT += multimedia

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        core/brightness.cpp \
        core/controller/alert.cpp \
        core/alertqueue.cpp \
        core/controller.cpp \
        core/controller/bottombar.cpp \
        core/controller/carparameter.cpp \
        core/controller/settings.cpp \
        core/controller/trip.cpp \
        core/controller/gauge.cpp \
        core/controller/topbar.cpp \
        core/senderhandler.cpp \
        core/soundhandler.cpp \
        core/uarthandler.cpp \
        core/can/deserializer.cpp \
        core/can/serializer.cpp \
        core/can/messagehandler.cpp \
        main.cpp

RESOURCES += resource.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    core/brightness.h \
    core/controller/alert.h \
    core/alertqueue.h \
    core/controller/bottombar.h \
    core/controller/carparameter.h \
    core/controller/gauge.h \
    core/controller/settings.h \
    core/controller/topbar.h \
    core/controller/trip.h \
    core/senderhandler.h \
    core/soundhandler.h \
    core/uarthandler.h
