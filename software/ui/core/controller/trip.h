#ifndef TRIP_H
#define TRIP_H

#include <QObject>

class Trip : public QObject
{
    Q_OBJECT
    Q_PROPERTY(bool engineStatus READ engineStatus WRITE setEngineStatus NOTIFY engineStatusChanged)
    Q_PROPERTY(int odometer READ odometer WRITE setOdometer NOTIFY odometerChanged)
    Q_PROPERTY(int autonomy READ autonomy WRITE setAutonomy NOTIFY autonomyChanged)
public:
    explicit Trip(QObject *parent = nullptr);

    bool engineStatus() const;
    void setEngineStatus(bool newEngineStatus);

    int odometer() const;
    void setOdometer(int newOdometer);

    int autonomy() const;
    void setAutonomy(int newAutonomy);

signals:

    void engineStatusChanged();
    void odometerChanged();

    void autonomyChanged();

private:
    bool m_engineStatus;
    int m_odometer;
    int m_autonomy;
};

#endif // TRIP_H
