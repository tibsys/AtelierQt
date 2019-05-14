#include "MaTache.h"
#include <QDebug>

MaTache::MaTache() {}

void MaTache::run()
{
    int iterations = 10;
    do
    {
        qDebug() << QString("Ma tâche s'exécute 10 fois. %1 restante(s).").arg(--iterations);
    } while(iterations > 0);
}
