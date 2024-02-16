#include "gauge.h"

Gauge::Gauge(QObject *parent)
    : QObject{parent}
    , m_speed(0)
    , m_rpm(0)
{
}

int Gauge::speed() const
{
    return m_speed;
}

void Gauge::setSpeed(int newSpeed)
{
    if (m_speed == newSpeed)
        return;
    m_speed = newSpeed;
    emit speedChanged();
}

int Gauge::rpm() const
{
    return m_rpm;
}

void Gauge::setRpm(int newRpm)
{
    if (m_rpm == newRpm)
        return;
    m_rpm = newRpm;
    emit rpmChanged();
}
