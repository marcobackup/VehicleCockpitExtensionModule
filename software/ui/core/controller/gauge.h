#ifndef GAUGE_H
#define GAUGE_H

#include <QObject>

class Gauge : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int speed READ speed WRITE setSpeed NOTIFY speedChanged)
    Q_PROPERTY(int rpm READ rpm WRITE setRpm NOTIFY rpmChanged)
public:
    explicit Gauge(QObject *parent = nullptr);

    int speed() const;
    void setSpeed(int newSpeed);

    int rpm() const;
    void setRpm(int newRpm);

signals:

    void speedChanged();

    void rpmChanged();

private:
    int m_speed;
    int m_rpm;
};

#endif // GAUGE_H
