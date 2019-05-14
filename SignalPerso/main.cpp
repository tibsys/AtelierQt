#include <QCoreApplication>
#include "Controleur.h"
#include "Rectangle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Compléter le code pour que l'émission de signal fonctionne    

    Controleur c;
    QObject::connect(&c, &Controleur::signalRectangle, &c, &Controleur::onSignalRectangle, Qt::QueuedConnection);

    qRegisterMetaType<toto::Rectangle>("Rectangle&");

    c.start();

    return a.exec();
}
