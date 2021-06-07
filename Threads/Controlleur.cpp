#include <QCoreApplication>
#include <QDebug>
#include <QTimer>

#include "Controlleur.h"
#include "MonThread.h"

#define MAUVAISE_APPROCHE 0

Controlleur::Controlleur(QObject *parent) :
    QObject(parent), total_(0), nbReponses_(0), nbThreadsTermines_(0)
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

#if(MAUVAISE_APPROCHE == 0)
    connect(th1, &MonThread::destroyed, [=] { termineApplicationSiThreadsDetruits(); });
    connect(th2, &MonThread::destroyed, [=] { termineApplicationSiThreadsDetruits(); });
    connect(th3, &MonThread::destroyed, [=] { termineApplicationSiThreadsDetruits(); });
    connect(th4, &MonThread::destroyed, [=] { termineApplicationSiThreadsDetruits(); });
    connect(th5, &MonThread::destroyed, [=] { termineApplicationSiThreadsDetruits(); });
#endif

    th1->start();
    th2->start();
    th3->start();
    th4->start();
    th5->start();
}

void Controlleur::termineApplicationSiThreadsDetruits()
{
    if(++nbThreadsTermines_ == 5) {
        qDebug() << "Utilisation de la bonne approche (déterminisite) pour terminer l'application";
        qApp->quit();
    }
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

#if(MAUVAISE_APPROCHE == 1)
        //Mauvaise approche : on définit une valeur arbitraire pour retarder
        //le moment de la fermeture de l'application pour laisser le temps aux
        //threads de se terminer...
        qDebug() << "Utilisation de la mauvaise approche (non-déterministe) pour terminer l'application";
        QTimer::singleShot(500, qApp, SLOT(quit())); //Termine l'exécution de la runloop
        //qApp->quit();
#endif
    }
}
