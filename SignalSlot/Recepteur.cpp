#include "Recepteur.h"
#include <QDebug>

Recepteur::Recepteur(QObject *parent) : QObject(parent)
{

}

void Recepteur::onUnSignal() {
    qDebug() << "Signal reçu";
}
