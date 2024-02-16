#ifndef UARTHANDLER_H
#define UARTHANDLER_H

#include <QObject>
#include <QtSerialPort/QSerialPort>

class UartHandler : public QObject
{
    Q_OBJECT
public:
    explicit UartHandler(QObject *parent = nullptr);
    ~UartHandler();
    typedef struct rxMessage {
        unsigned int arbitration_id;
        int dlc;
        uint8_t *data;
    } rxMessage;
    typedef struct settingsEcmStatusStruct {
        unsigned int theme;
        unsigned int language;
        unsigned int audioStatus;
    } settingsEcmStatusStruct;

    void send(QByteArray payload);

private slots:
    void handleReadyRead();

signals:
    void dataReceived(UartHandler::rxMessage data);
    void settingsEcmStatusReceived(UartHandler::settingsEcmStatusStruct settingsReceived);

private:
    QSerialPort *serialPort;

    void handleRxMessage(const QByteArray &data);
    void setupSerialPort();

};

#endif // UARTHANDLER_H
