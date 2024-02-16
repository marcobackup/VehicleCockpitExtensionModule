#include "bottombar.h"

BottomBar::BottomBar(QObject *parent)
    : QObject{parent}
    , m_handBrakeStatus(false)
    , m_steeringWheelFaultStatus(false)
    , m_sbrRLStatus(false)
    , m_sbrRCStatus(false)
    , m_sbrRRStatus(false)
    , m_lightFaultStatus(false)
    , m_bonnetStatus(false)
{
}

bool BottomBar::handBrakeStatus() const
{
    return m_handBrakeStatus;
}

void BottomBar::setHandBrakeStatus(bool newHandBrakeStatus)
{
    if (m_handBrakeStatus == newHandBrakeStatus)
        return;
    m_handBrakeStatus = newHandBrakeStatus;
    emit handBrakeStatusChanged();
}

bool BottomBar::steeringWheelFaultStatus() const
{
    return m_steeringWheelFaultStatus;
}

void BottomBar::setSteeringWheelFaultStatus(bool newSteeringWheelFaultStatus)
{
    if (m_steeringWheelFaultStatus == newSteeringWheelFaultStatus)
        return;
    m_steeringWheelFaultStatus = newSteeringWheelFaultStatus;
    emit steeringWheelFaultStatusChanged();
}

bool BottomBar::sbrRLStatus() const
{
    return m_sbrRLStatus;
}

void BottomBar::setSbrRLStatus(bool newSbrRLStatus)
{
    if (m_sbrRLStatus == newSbrRLStatus)
        return;
    m_sbrRLStatus = newSbrRLStatus;
    emit sbrRLStatusChanged();
}

bool BottomBar::sbrRCStatus() const
{
    return m_sbrRCStatus;
}

void BottomBar::setSbrRCStatus(bool newSbrRCStatus)
{
    if (m_sbrRCStatus == newSbrRCStatus)
        return;
    m_sbrRCStatus = newSbrRCStatus;
    emit sbrRCStatusChanged();
}

bool BottomBar::sbrRRStatus() const
{
    return m_sbrRRStatus;
}

void BottomBar::setSbrRRStatus(bool newSbrRRStatus)
{
    if (m_sbrRRStatus == newSbrRRStatus)
        return;
    m_sbrRRStatus = newSbrRRStatus;
    emit sbrRRStatusChanged();
}

bool BottomBar::lightFaultStatus() const
{
    return m_lightFaultStatus;
}

void BottomBar::setLightFaultStatus(bool newLightFaultStatus)
{
    if (m_lightFaultStatus == newLightFaultStatus)
        return;
    m_lightFaultStatus = newLightFaultStatus;
    emit lightFaultStatusChanged();
}

bool BottomBar::bonnetStatus() const
{
    return m_bonnetStatus;
}

void BottomBar::setBonnetStatus(bool newBonnetStatus)
{
    if (m_bonnetStatus == newBonnetStatus)
        return;
    m_bonnetStatus = newBonnetStatus;
    emit bonnetStatusChanged();
}
