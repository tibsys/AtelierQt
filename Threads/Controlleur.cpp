#include <QCoreApplication>
#include <QDebug>

#include "Controlleur.h"
#include "MonThread.h"

Controlleur::Controlleur(QObject *parent) :
    QObject(parent), total_(0), nbReponses_(0)
{
}

void Controlleur::start()
{
    MonThread* th1 = new MonThread(1, 5, this);
    MonThread* th2 = new MonThread(6, 10, this);
    MonThread* th3 = new MonThread(11, 15, this);
    MonThread* th4 = new MonThread(16, 20, this);
    MonThread* th5 = new MonThread(21, 25, this);

    connect(th1, SIGNAL(signalNouvelleValeur(uint)), this, SLOT(onNouvelleValeur(uint)));
    connect(th2, SIGNAL(signalNouvelleValeur(uint)), this, SLOT(onNouvelleValeur(uint)));
    connect(th3, SIGNAL(signalNouvelleValeur(uint)), this, SLOT(onNouvelleValeur(uint)));
    connect(th4, SIGNAL(signalNouvelleValeur(uint)), this, SLOT(onNouvelleValeur(uint)));
    connect(th5, SIGNAL(signalNouvelleValeur(uint)), this, SLOT(onNouvelleValeur(uint)));

    th1->start();
    th2->start();
    th3->start();
    th4->start();
    th5->start();
}

void Controlleur::onNouvelleValeur(uint val)
{
    total_ += val;
    nbReponses_ += 1;

    qDebug() << "";
    qDebug() << "Nouvelle valeur : " << val;

    if(nbReponses_ == 5)
    {
        qDebug() << "Calcul terminé, le total est : " << total_;
        qApp->quit(); //Termine l'exécution de la runloop
    }
}
