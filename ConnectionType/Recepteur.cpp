#include "Recepteur.h"
#include <QDebug>
#include <QDateTime>

Recepteur::Recepteur(QObject *parent) : QObject(parent)
{

}

void Recepteur::onUnSignal() {
    qDebug() << "Signal reçu le " << QDateTime::currentMSecsSinceEpoch();
}
