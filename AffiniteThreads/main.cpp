#include <QCoreApplication>
#include <QDebug>
#include "Objet.h"
#include "Controller.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << "Adresse de a : " << &a;
    qDebug() << "   Current thread id : " << a.thread()->currentThreadId();

    Controller ctrl;
    ctrl.start();    

    return a.exec();
}

/*
     Thread de a : 0x0dc0



*/
