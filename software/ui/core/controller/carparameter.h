#ifndef CARPARAMETER_H
#define CARPARAMETER_H

#include <QObject>

class CarParameter : public QObject
{
    Q_OBJECT
    Q_PROPERTY(float fuelLevel READ fuelLevel WRITE setFuelLevel NOTIFY fuelLevelChanged)
    Q_PROPERTY(bool lowFuelLevelWarningStatus READ lowFuelLevelWarningStatus WRITE setLowFuelLevelWarningStatus NOTIFY lowFuelLevelWarningStatusChanged)
    Q_PROPERTY(float coolantTemperature READ coolantTemperature WRITE setCoolantTemperature NOTIFY coolantTemperatureChanged)
    Q_PROPERTY(bool highCoolantTemperatureWarningStatus READ highCoolantTemperatureWarningStatus WRITE setHighCoolantTemperatureWarningStatus NOTIFY highCoolantTemperatureWarningStatusChanged)
    Q_PROPERTY(float boostPressure READ boostPressure WRITE setBoostPressure NOTIFY boostPressureChanged)
    Q_PROPERTY(float batteryVoltage READ batteryVoltage WRITE setBatteryVoltage NOTIFY batteryVoltageChanged)
public:
    explicit CarParameter(QObject *parent = nullptr);

    float fuelLevel() const;
    void setFuelLevel(float newFuelLevel);

    bool lowFuelLevelWarningStatus() const;
    void setLowFuelLevelWarningStatus(bool newLowFuelLevelWarningStatus);

    float coolantTemperature() const;
    void setCoolantTemperature(float newCoolantTemperature);

    bool highCoolantTemperatureWarningStatus() const;
    void setHighCoolantTemperatureWarningStatus(bool newHighCoolantTemperatureWarningStatus);

    float boostPressure() const;
    void setBoostPressure(float newBoostPressure);

    float batteryVoltage() const;
    void setBatteryVoltage(float newBatteryVoltage);

signals:

    void fuelLevelChanged();
    void lowFuelLevelWarningStatusChanged();

    void coolantTemperatureChanged();

    void highCoolantTemperatureWarningStatusChanged();

    void boostPressureChanged();

    void batteryVoltageChanged();

private:
    float m_fuelLevel;
    bool m_lowFuelLevelWarningStatus;
    float m_coolantTemperature;
    bool m_highCoolantTemperatureWarningStatus;
    float m_boostPressure;
    float m_batteryVoltage;
};

#endif // CARPARAMETER_H
