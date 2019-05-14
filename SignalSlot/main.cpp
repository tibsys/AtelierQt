#include <QCoreApplication>
#include "Emetteur.h"
#include "Recepteur.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //TP 1 : Compléter le code pour qu'un signal soit émis et que la ligne "Signal reçu" s'affiche en console
    Emetteur *e = new Emetteur(&a);
    Recepteur r;

    QObject::connect(e, SIGNAL(signalUnSignal()), &r, SLOT(onUnSignal()));


    //TP 2 : Dupliquer la connexion plusieurs fois et observer le résultat
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);

    e->emetSignal();

    //TP 3 : Supprime la ligne ci-dessous et observer le résultat
    //return a.exec();
}
