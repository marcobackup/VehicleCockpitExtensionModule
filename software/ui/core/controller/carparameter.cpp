#include "carparameter.h"

CarParameter::CarParameter(QObject *parent)
    : QObject{parent}
    , m_fuelLevel(0.0)
    , m_lowFuelLevelWarningStatus(false)
    , m_coolantTemperature(0.0)
    , m_highCoolantTemperatureWarningStatus(false)
    , m_boostPressure(0.0)
    , m_batteryVoltage(0.0)
{

}

float CarParameter::fuelLevel() const
{
    return m_fuelLevel;
}

void CarParameter::setFuelLevel(float newFuelLevel)
{
    if (qFuzzyCompare(m_fuelLevel, newFuelLevel))
        return;
    m_fuelLevel = newFuelLevel;
    emit fuelLevelChanged();
}

bool CarParameter::lowFuelLevelWarningStatus() const
{
    return m_lowFuelLevelWarningStatus;
}

void CarParameter::setLowFuelLevelWarningStatus(bool newLowFuelLevelWarningStatus)
{
    if (m_lowFuelLevelWarningStatus == newLowFuelLevelWarningStatus)
        return;
    m_lowFuelLevelWarningStatus = newLowFuelLevelWarningStatus;
    emit lowFuelLevelWarningStatusChanged();
}

float CarParameter::coolantTemperature() const
{
    return m_coolantTemperature;
}

void CarParameter::setCoolantTemperature(float newCoolantTemperature)
{
    if (qFuzzyCompare(m_coolantTemperature, newCoolantTemperature))
        return;
    m_coolantTemperature = newCoolantTemperature;
    emit coolantTemperatureChanged();
}

bool CarParameter::highCoolantTemperatureWarningStatus() const
{
    return m_highCoolantTemperatureWarningStatus;
}

void CarParameter::setHighCoolantTemperatureWarningStatus(bool newHighCoolantTemperatureWarningStatus)
{
    if (m_highCoolantTemperatureWarningStatus == newHighCoolantTemperatureWarningStatus)
        return;
    m_highCoolantTemperatureWarningStatus = newHighCoolantTemperatureWarningStatus;
    emit highCoolantTemperatureWarningStatusChanged();
}

float CarParameter::boostPressure() const
{
    return m_boostPressure;
}

void CarParameter::setBoostPressure(float newBoostPressure)
{
    if (qFuzzyCompare(m_boostPressure, newBoostPressure))
        return;
    m_boostPressure = newBoostPressure;
    emit boostPressureChanged();
}

float CarParameter::batteryVoltage() const
{
    return m_batteryVoltage;
}

void CarParameter::setBatteryVoltage(float newBatteryVoltage)
{
    if (qFuzzyCompare(m_batteryVoltage, newBatteryVoltage))
        return;
    m_batteryVoltage = newBatteryVoltage;
    emit batteryVoltageChanged();
}
