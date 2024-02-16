#ifndef BOTTOMBAR_H
#define BOTTOMBAR_H

#include <QObject>

class BottomBar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool handBrakeStatus READ handBrakeStatus WRITE setHandBrakeStatus NOTIFY handBrakeStatusChanged)
    Q_PROPERTY(bool steeringWheelFaultStatus READ steeringWheelFaultStatus WRITE setSteeringWheelFaultStatus NOTIFY steeringWheelFaultStatusChanged)
    Q_PROPERTY(bool sbrRLStatus READ sbrRLStatus WRITE setSbrRLStatus NOTIFY sbrRLStatusChanged)
    Q_PROPERTY(bool sbrRCStatus READ sbrRCStatus WRITE setSbrRCStatus NOTIFY sbrRCStatusChanged)
    Q_PROPERTY(bool sbrRRStatus READ sbrRRStatus WRITE setSbrRRStatus NOTIFY sbrRRStatusChanged)
    Q_PROPERTY(bool lightFaultStatus READ lightFaultStatus WRITE setLightFaultStatus NOTIFY lightFaultStatusChanged)
    Q_PROPERTY(bool bonnetStatus READ bonnetStatus WRITE setBonnetStatus NOTIFY bonnetStatusChanged)
public:
    explicit BottomBar(QObject *parent = nullptr);

    bool handBrakeStatus() const;
    void setHandBrakeStatus(bool newHandBrakeStatus);

    bool steeringWheelFaultStatus() const;
    void setSteeringWheelFaultStatus(bool newSteeringWheelFaultStatus);

    bool sbrRLStatus() const;
    void setSbrRLStatus(bool newSbrRLStatus);

    bool sbrRCStatus() const;
    void setSbrRCStatus(bool newSbrRCStatus);

    bool sbrRRStatus() const;
    void setSbrRRStatus(bool newSbrRRStatus);

    bool lightFaultStatus() const;
    void setLightFaultStatus(bool newLightFaultStatus);

    bool bonnetStatus() const;
    void setBonnetStatus(bool newBonnetStatus);

signals:

    void handBrakeStatusChanged();
    void steeringWheelFaultStatusChanged();

    void sbrRLStatusChanged();

    void sbrRCStatusChanged();

    void sbrRRStatusChanged();

    void lightFaultStatusChanged();

    void bonnetStatusChanged();

private:
    bool m_handBrakeStatus;
    bool m_steeringWheelFaultStatus;
    bool m_sbrRLStatus;
    bool m_sbrRCStatus;
    bool m_sbrRRStatus;
    bool m_lightFaultStatus;
    bool m_bonnetStatus;
};

#endif // BOTTOMBAR_H
