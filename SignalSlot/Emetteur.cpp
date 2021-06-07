#include "Emetteur.h"
#include <QDebug>

Emetteur::Emetteur(QObject *parent) : QObject(parent)
{

}

void Emetteur::emetSignal() {
    emit signalUnSignal();
    qDebug() << "Signal émis";
}
