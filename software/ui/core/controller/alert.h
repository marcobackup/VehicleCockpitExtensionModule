#ifndef ALERT_H
#define ALERT_H

#include <QObject>

class Alert : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString type READ type WRITE setType NOTIFY typeChanged FINAL)
    Q_PROPERTY(QString icon READ icon WRITE setIcon NOTIFY iconChanged FINAL)
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged FINAL)
    Q_PROPERTY(QString description READ description WRITE setDescription NOTIFY descriptionChanged FINAL)
public:
    explicit Alert(QObject *parent = nullptr);

    const QString &type() const;
    void setType(const QString &newType);

    const QString &icon() const;
    void setIcon(const QString &newIcon);

    const QString &title() const;
    void setTitle(const QString &newTitle);

    const QString &description() const;
    void setDescription(const QString &newDescription);

signals:

    void typeChanged();
    void iconChanged();

    void titleChanged();

    void descriptionChanged();

private:
    QString m_type;
    QString m_icon;
    QString m_title;
    QString m_description;
};

#endif // ALERT_H
