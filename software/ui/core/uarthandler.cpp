#include "uarthandler.h"
#include <QDebug>
#include <QByteArray>
#include <QtSerialPort/QSerialPort>
#include <QtSerialPort/QSerialPortInfo>
#include <QRegularExpression>
#include <QRegularExpressionMatch>

UartHandler::UartHandler(QObject *parent)
    : QObject{parent} {
    serialPort = new QSerialPort(this);
    connect(serialPort, &QSerialPort::readyRead, this, &UartHandler::handleReadyRead, Qt::QueuedConnection);
    setupSerialPort();
}

UartHandler::~UartHandler() {
    if(serialPort->isOpen())
        serialPort->close();
}

void UartHandler::handleReadyRead() {
    if(!serialPort->canReadLine())
        return;
    QByteArray byteArray = serialPort->readAll();
    handleRxMessage(byteArray);
}

void UartHandler::handleRxMessage(const QByteArray &data) {
    QString dataString(data);
    QRegularExpressionMatch match;
    QStringList lines = dataString.split("\n", Qt::SkipEmptyParts);
    rxMessage rxMsg;
    settingsEcmStatusStruct settingsEcmStatusConfig;

    for (const QString &line : lines) {
        QRegularExpression regex("(\\d+)#(\\d+)#(.+)");
        match = regex.match(line);

        if (match.hasMatch()) {
            // Estrai l'ID, la lunghezza dei dati e i dati stessi
            QStringList dataValues = match.captured(3).split(',');
            rxMsg.arbitration_id = match.captured(1).toInt();
            rxMsg.dlc = match.captured(2).toInt();

            // QStringList to uint8_t array
            QVector<uint8_t> uint8Array;
            for (const QString& hexString : dataValues) {
                bool conversionOk;
                uint8_t value = static_cast<uint8_t>(hexString.toUInt(&conversionOk, 16));
                uint8Array.append(value);
            }
            rxMsg.data = uint8Array.data();
            emit dataReceived(rxMsg);
        } else {
            QRegularExpression regexSettings("^eeprom#ecmStatus#read#(\\d+),(\\d+),(\\d+)");
            match = regexSettings.match(line);

            if(match.hasMatch()) {
                settingsEcmStatusConfig.theme = match.captured(1).toInt();
                settingsEcmStatusConfig.language = match.captured(2).toInt();
                settingsEcmStatusConfig.audioStatus = match.captured(3).toInt();
                emit settingsEcmStatusReceived(settingsEcmStatusConfig);
            }
        }
    }
}

void UartHandler::send(QByteArray payload) {
    if(serialPort->isOpen()) {
        quint64 bytesWritten = serialPort->write(payload);
        if (bytesWritten == -1)
            qWarning() << "Error during bytes writing: " << serialPort->errorString();
    }
}

void UartHandler::setupSerialPort() {
    QList<QSerialPortInfo> serialPortInfoList = QSerialPortInfo::availablePorts();
    if (serialPortInfoList.isEmpty()) {
        qWarning() << "No serial port found";
        return;
    }

    // serial port parameters
    serialPort->setPort(serialPortInfoList.first());
    serialPort->setBaudRate(QSerialPort::Baud115200);
    serialPort->setDataBits(QSerialPort::Data8);
    serialPort->setFlowControl(QSerialPort::NoFlowControl);
    serialPort->setParity(QSerialPort::NoParity);
    serialPort->setStopBits(QSerialPort::OneStop);

    if (!serialPort->open(QIODevice::ReadWrite)) {
        qWarning() << "Something went wrong, serial port not opened";
        return;
    } else
        qDebug() << "Interfaced with" << serialPort->portName() << "serial port";
}
