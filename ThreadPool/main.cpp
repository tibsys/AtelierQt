#include <QCoreApplication>
#include <QThreadPool>
#include <QThread>
#include <QDebug>
#include "MaTache.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "Current thread count: " << QThreadPool::globalInstance()->maxThreadCount();
    QThreadPool::globalInstance()->setMaxThreadCount(3);
    MaTache* tache1 = new MaTache;
    QThreadPool::globalInstance()->start(tache1);    

    int res = a.exec();
    QThreadPool::globalInstance()->waitForDone();
    return res;
}
