#include <QCoreApplication>
#include "Emetteur.h"
#include "Recepteur.h"

#define TP 4

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Emetteur *e = new Emetteur(&a);
    Recepteur r;

#if(TP == 1)
    //Compléter le code pour qu'un signal soit émis et que la ligne "Signal reçu" s'affiche en console

    e->emetSignal();
#endif

#if(TP == 2)
    //TP 2 : Connexion dupliquée : observer le résultat
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);

    e->emetSignal();
#endif

#if(TP == 3 || TP == 4)
    //TP 3 : émissions multiples
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);
    QObject::connect(e, &Emetteur::signalUnSignal, &r, &Recepteur::onUnSignal);

    e->emetSignal();
    e->emetSignal();
#endif

#if(TP < 4)
    return a.exec();
#endif
}
