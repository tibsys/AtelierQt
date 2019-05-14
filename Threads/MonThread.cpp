#include <QDebug>

#include "MonThread.h"

MonThread::MonThread(uint debut, uint fin, QObject *parent) :
    QObject(parent), debut_(debut), fin_(fin), thread_(new QThread(this))
{

}

void MonThread::start()
{    
    MonWorker* worker = new MonWorker(debut_, fin_);
    connect(worker, SIGNAL(signalWorkerEnded(uint)), this, SLOT(onWorkerEnded(uint)));
    connect(worker, SIGNAL(destroyed()), thread_, SLOT(deleteLater())); //Au-nettoyage du thread
    //connect(worker, SIGNAL(signalWorkerEnded(uint)), this, SIGNAL(signalNouvelleValeur(uint)));

    connect(thread_, SIGNAL(finished()), worker, SLOT(deleteLater()));x
    worker->moveToThread(thread_);
    QMetaObject::invokeMethod(worker, "start", Qt::QueuedConnection); //Ne pas appeler directement la fonction start() !
    thread_->start();

    qDebug() << "MonThread::start, thread id=" << thread()->currentThreadId();
    qDebug() << "MonThread::start (syntaxe2), thread id=";

}

void MonThread::stop()
{
    //Mettre du code ici pour permettre d'interrompte le fonctionnement du worker
}

void MonThread::onWorkerEnded(uint val)
{
    emit signalNouvelleValeur(val);
    thread_->exit(); //On en profite pour terminer le thread
}

MonWorker::MonWorker(uint debut, uint fin, QObject *parent)
    : QObject(parent), valeur_(0), debut_(debut), fin_(fin)
{}

void MonWorker::start()
{
    qDebug() << "Worker::start, thread id=" << thread()->currentThreadId();
    uint somme = 0;
    for(uint i = debut_ ; i <= fin_ ; i++)
    {
        somme += i;
    }

    emit signalWorkerEnded(somme);
}

void MonWorker::stop()
{
    //Mettre du code ici pour interrompre le fonctionnement du worker
}
