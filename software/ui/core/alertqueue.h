#ifndef ALERTQUEUE_H
#define ALERTQUEUE_H

#include <QObject>
#include <QQueue>
#include "core/controller/alert.h"

class AlertQueue : public QObject
{
    Q_OBJECT
public:
    explicit AlertQueue(QObject *parent = nullptr);
    Q_INVOKABLE void addWarningAlert(QString icon, QString title, QString description);
    Q_INVOKABLE void addFaultAlert(QString icon, QString title, QString description);
    Q_INVOKABLE QObject *getFrontAlert();
private:
    QQueue<Alert *> alertsQueue;
signals:
    void alertsQueueChanged();
};

#endif // ALERTQUEUE_H
