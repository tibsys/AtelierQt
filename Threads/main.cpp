#include <QCoreApplication>
#include "Controlleur.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    
    Controlleur ctrl;
    ctrl.start();

    return a.exec();
}
