#include "Emetteur.h"

Emetteur::Emetteur(QObject *parent) : QObject(parent)
{

}

void Emetteur::emetSignal() {
    emit signalUnSignal();
}
