#include <QCoreApplication>
#include <Controller.h>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Controller c;

    //Décommenter l'un ou l'autre des appels
    //c.start1();
    //c.start2();
    c.start3();

    return a.exec();
}
