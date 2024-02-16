#include "alertqueue.h"
#include <QQueue>
#include "core/controller/alert.h"

AlertQueue::AlertQueue(QObject *parent)
    : QObject{parent} {
}

void AlertQueue::addWarningAlert(QString icon, QString title, QString description) {
    Alert *newWarning = new Alert(this);
    newWarning->setType("warning");
    newWarning->setIcon(icon);
    newWarning->setTitle(title);
    newWarning->setDescription(description);
    alertsQueue.enqueue(newWarning);
    emit alertsQueueChanged();
}

void AlertQueue::addFaultAlert(QString icon, QString title, QString description) {
    Alert *newFault = new Alert(this);
    newFault->setType("fault");
    newFault->setIcon(icon);
    newFault->setTitle(title);
    newFault->setDescription(description);
    alertsQueue.enqueue(newFault);
    emit alertsQueueChanged();
}

QObject *AlertQueue::getFrontAlert() {
    if(!alertsQueue.isEmpty()) {
        Alert* frontAlert = alertsQueue.front();
        alertsQueue.dequeue();
        return dynamic_cast<QObject*>(frontAlert);  // Effettua il cast a QObject*
    } else {
        return nullptr;
    }
}
