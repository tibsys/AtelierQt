#include "Controller.h"
#include <QThread>
#include <QDebug>
#include <QTimer>

Controller::Controller(QObject *parent) : QObject(parent)
{
    qDebug() << "*** 1 - Constructeur de Controller...";
    qDebug() << "   Current thread id : " << thread()->currentThreadId();
}

void Controller::start()
{
    qDebug() << "*** 2 - Controller::start...";
    qDebug() << "   Current thread id : " << thread()->currentThreadId();
    qDebug() << "";

    Objet *o1 = new Objet(this);
    o1->setObjectName("o1");
    qDebug() << "*** 1 -> o1";
    qDebug() << "   Thread id : " << o1->thread()->currentThreadId();

    QThread *t2 = new QThread(this);
    t2->setObjectName("t2");
    t2->start();
    qDebug() << "*** 3 - Thread t2";
    qDebug() << "   Current thread id : " << t2->thread()->currentThreadId();
    qDebug() << "";

    Objet *o2 = new Objet;
    o2->setObjectName("o2");
    qDebug() << "*** 4 -> Appel de fonction debugObjet()";
    o2->debugObjet();
    qDebug() << "*** 5 -> Déplacement dans le thread t2";
    o2->moveToThread(t2);
    qDebug() << "*** 6 -> Appel de fonction debugObjet()";
    o2->debugObjet();
    qDebug() << "*** 7 -> Appel de fonction debugObjetNonSlot()";
    o2->debugObjetNonSlot();
    qDebug() << "*** 8 -> Récupération du thread id sur l'objet : " << o2->thread()->currentThreadId();
    qDebug() << "*** 9 -> Appel de fonction debugObjet() par timer (timeout=0)";
    QTimer::singleShot(0, o2, SLOT(debugObjet()));
    qDebug() << "*** 10 -> Appel de fonction debugObjetFiable()";
    o2->debugObjetFiable();

    o2->deleteLater();
}
