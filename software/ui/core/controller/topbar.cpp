#include "topbar.h"
#include "core/brightness.h"

TopBar::TopBar(Brightness *brightnessHandler, QObject *parent)
    : QObject{parent}
    , brightnessHandler(brightnessHandler)
    , m_leftArrowStatus(false)
    , m_rightArrowStatus(false)
    , m_lowBeamLightStatus(false)
    , m_highBeamLightStatus(false)
    , m_environmentalTemperature(0.0)
    , m_hour("00:00")
{
}

bool TopBar::leftArrowStatus() const
{
    return m_leftArrowStatus;
}

void TopBar::setLeftArrowStatus(bool newLeftArrowStatus)
{
    if (m_leftArrowStatus == newLeftArrowStatus)
        return;
    m_leftArrowStatus = newLeftArrowStatus;
    emit leftArrowStatusChanged();
}

bool TopBar::rightArrowStatus() const
{
    return m_rightArrowStatus;
}

void TopBar::setRightArrowStatus(bool newRightArrow)
{
    if (m_rightArrowStatus == newRightArrow)
        return;
    m_rightArrowStatus = newRightArrow;
    emit rightArrowStatusChanged();
}

bool TopBar::lowBeamLightStatus() const
{
    return m_lowBeamLightStatus;
}

void TopBar::setLowBeamLightStatus(bool newLowBeamLightStatus)
{
    if (m_lowBeamLightStatus == newLowBeamLightStatus)
        return;
    if(newLowBeamLightStatus)
        brightnessHandler.setBrightness(125);
    else
        brightnessHandler.setBrightness(255);
    m_lowBeamLightStatus = newLowBeamLightStatus;
    emit lowBeamLightStatusChanged();
}

bool TopBar::highBeamLightStatus() const
{
    return m_highBeamLightStatus;
}

void TopBar::setHighBeamLightStatus(bool newHighBeamLightStatus)
{
    if (m_highBeamLightStatus == newHighBeamLightStatus)
        return;
    m_highBeamLightStatus = newHighBeamLightStatus;
    emit highBeamLightStatusChanged();
}

float TopBar::environmentalTemperature() const
{
    return m_environmentalTemperature;
}

void TopBar::setEnvironmentalTemperature(float newEnvironmentalTemperature)
{
    if (qFuzzyCompare(m_environmentalTemperature, newEnvironmentalTemperature))
        return;
    m_environmentalTemperature = newEnvironmentalTemperature;
    emit environmentalTemperatureChanged();
}

const QString &TopBar::hour() const
{
    return m_hour;
}

void TopBar::setHour(const QString &newHour)
{
    if (m_hour == newHour)
        return;
    m_hour = newHour;
    emit hourChanged();
}
