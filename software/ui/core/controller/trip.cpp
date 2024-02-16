#include "trip.h"

Trip::Trip(QObject *parent)
    : QObject{parent}
{

}

bool Trip::engineStatus() const
{
    return m_engineStatus;
}

void Trip::setEngineStatus(bool newEngineStatus)
{
    if (m_engineStatus == newEngineStatus)
        return;
    m_engineStatus = newEngineStatus;
    emit engineStatusChanged();
}

int Trip::odometer() const
{
    return m_odometer;
}

void Trip::setOdometer(int newOdometer)
{
    if (m_odometer == newOdometer)
        return;
    m_odometer = newOdometer;
    emit odometerChanged();
}

int Trip::autonomy() const
{
    return m_autonomy;
}

void Trip::setAutonomy(int newAutonomy)
{
    if (m_autonomy == newAutonomy)
        return;
    m_autonomy = newAutonomy;
    emit autonomyChanged();
}
