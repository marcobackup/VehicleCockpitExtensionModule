#ifndef TOPBAR_H
#define TOPBAR_H

#include <QObject>
#include "core/brightness.h"

class TopBar : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool leftArrowStatus READ leftArrowStatus WRITE setLeftArrowStatus NOTIFY leftArrowStatusChanged)
    Q_PROPERTY(bool rightArrowStatus READ rightArrowStatus WRITE setRightArrowStatus NOTIFY rightArrowStatusChanged)
    Q_PROPERTY(bool lowBeamLightStatus READ lowBeamLightStatus WRITE setLowBeamLightStatus NOTIFY lowBeamLightStatusChanged)
    Q_PROPERTY(bool highBeamLightStatus READ highBeamLightStatus WRITE setHighBeamLightStatus NOTIFY highBeamLightStatusChanged)
    Q_PROPERTY(float environmentalTemperature READ environmentalTemperature WRITE setEnvironmentalTemperature NOTIFY environmentalTemperatureChanged)
    Q_PROPERTY(QString hour READ hour WRITE setHour NOTIFY hourChanged)
public:
    explicit TopBar(Brightness *brightnessHandler, QObject *parent = nullptr);

    bool leftArrowStatus() const;
    void setLeftArrowStatus(bool newLeftArrowStatus);

    bool rightArrowStatus() const;
    void setRightArrowStatus(bool newRightArrowStatus);

    bool lowBeamLightStatus() const;
    void setLowBeamLightStatus(bool newLowBeamLightStatus);

    bool highBeamLightStatus() const;
    void setHighBeamLightStatus(bool newHighBeamLightStatus);

    float environmentalTemperature() const;
    void setEnvironmentalTemperature(float newEnvironmentalTemperature);

    const QString &hour() const;
    void setHour(const QString &newHour);

signals:

    void leftArrowStatusChanged();
    void rightArrowStatusChanged();

    void lowBeamLightStatusChanged();

    void highBeamLightStatusChanged();

    void environmentalTemperatureChanged();

    void hourChanged();

private:
    Brightness brightnessHandler;
    bool m_leftArrowStatus;
    bool m_rightArrowStatus;
    bool m_lowBeamLightStatus;
    bool m_highBeamLightStatus;
    float m_environmentalTemperature;
    QString m_hour;
};

#endif // TOPBAR_H
