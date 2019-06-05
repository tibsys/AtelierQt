#include <QDebug>
#include <QRandomGenerator>
#include "MonThread.h"

MonThread::MonThread(uint debut, uint fin, QObject *parent) :
    QObject(parent), debut_(debut), fin_(fin), thread_(new QThread(this))
{

}

void MonThread::start()
{    
    MonWorker* worker = new MonWorker(debut_, fin_);
    connect(worker, SIGNAL(signalWorkerEnded(uint)), this, SLOT(onWorkerEnded(uint)));
    connect(worker, SIGNAL(destroyed()), thread_, SLOT(deleteLater())); //Auto-nettoyage du thread

    connect(thread_, SIGNAL(finished()), worker, SLOT(deleteLater()));
    worker->moveToThread(thread_);
    QMetaObject::invokeMethod(worker, "start", Qt::QueuedConnection); //Ne pas appeler directement la fonction start() !
    thread_->start();
    thread_->setProperty("tid", QRandomGenerator::global()->generate()%100);
    connect(thread_, &QThread::started, [=]{ qDebug() << "MonThread::start, thread " << thread_->property("tid").toUInt() << " id=" << thread_->currentThreadId(); });
    connect(thread_, &QObject::destroyed, this, &QObject::deleteLater);

    qDebug() << "";
    qDebug() << "MonThread::start, caller thread id=" << thread()->currentThreadId();

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
    qDebug() << "";
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
