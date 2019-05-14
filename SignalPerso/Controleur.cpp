#include "Controleur.h"
#include <QDebug>

Controleur::Controleur(QObject *parent) : QObject(parent)
{

}

void Controleur::onSignalRectangle(toto::Rectangle& rect) {
    qDebug() << "Signal recu";
}

void Controleur::start() {
    toto::Rectangle r;
    emit signalRectangle(r);
}
