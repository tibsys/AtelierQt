#include <QCoreApplication>
#include <QThread>
#include "Emetteur.h"
#include "Recepteur.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Emetteur e;
    Recepteur r;

    //TP 1 : Décommenter successivement les lignes ci-dessous
    //QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);
    QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, static_cast<Qt::ConnectionType>(Qt::QueuedConnection));
    QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, static_cast<Qt::ConnectionType>(Qt::QueuedConnection));
    QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, static_cast<Qt::ConnectionType>(Qt::QueuedConnection));
    QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, static_cast<Qt::ConnectionType>(Qt::QueuedConnection | Qt::UniqueConnection));
    QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, static_cast<Qt::ConnectionType>(Qt::QueuedConnection));
    QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, static_cast<Qt::ConnectionType>(Qt::DirectConnection));
    //QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, Qt::BlockingQueuedConnection);
    //QObject::connect(&e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal, Qt::UniqueConnection);

    e.emetSignal();

    //TP 2 : Commenter la ligne ci-dessous et observer le résultat
    return a.exec();
}
