#include "alert.h"

Alert::Alert(QObject *parent)
    : QObject{parent}
{
}

const QString &Alert::type() const
{
    return m_type;
}

void Alert::setType(const QString &newType)
{
    if (m_type == newType)
        return;
    m_type = newType;
    emit typeChanged();
}

const QString &Alert::icon() const
{
    return m_icon;
}

void Alert::setIcon(const QString &newIcon)
{
    if (m_icon == newIcon)
        return;
    m_icon = newIcon;
    emit iconChanged();
}

const QString &Alert::title() const
{
    return m_title;
}

void Alert::setTitle(const QString &newTitle)
{
    if (m_title == newTitle)
        return;
    m_title = newTitle;
    emit titleChanged();
}

const QString &Alert::description() const
{
    return m_description;
}

void Alert::setDescription(const QString &newDescription)
{
    if (m_description == newDescription)
        return;
    m_description = newDescription;
    emit descriptionChanged();
}
