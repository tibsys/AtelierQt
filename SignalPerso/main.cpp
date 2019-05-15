#include <QCoreApplication>
#include "Controleur.h"
#include "Rectangle.h"

//Choisir le TP
#define TP 2

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Compléter le code pour que l'émission de signal fonctionne    

    Controleur c;

#if(TP == 1)
    QObject::connect(&c, &Controleur::signalRectangle, &c, &Controleur::onSignalRectangle, Qt::QueuedConnection);
#endif

#if(TP == 2)
    QObject::connect(&c, &Controleur::signalRectangle, &c, &Controleur::onSignalRectangle);
#endif

    c.start();

    return a.exec();
}
