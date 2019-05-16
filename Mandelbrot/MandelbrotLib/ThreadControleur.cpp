#include "ThreadControleur.h"
#include <QThread>
#include "MandelbrotControleur.h"

ThreadControleur::ThreadControleur(QObject *parent)
    : QObject(parent), nbThreads_(0), nbThreadsTermines_(0), zoom_(200), iterations_(50), largeur_(1), hauteur_(1), stoppe_(false)
{ }

void ThreadControleur::calculeImage()
{
    nbThreadsTermines_ = 0;
    stoppe_ = false;
    qDebug() << QString("Dimensions de l'image à calculer : largeur=%1, hauteur=%2").arg(largeur_).arg(hauteur_);

    for(int i = 0 ; i < nbThreads_ ; i++) {
        //On découpe l'image en autant de portions (en vertical) qu'il y a de threads
        QThread *th = new QThread(this);        
        MandelbrotControleur* ctrl = new MandelbrotControleur(&stoppe_);
        ctrl->moveToThread(th);
        connect(ctrl, &MandelbrotControleur::signalNouveauPoint, this, &ThreadControleur::signalNouveauPoint); //Réémission du signal
        connect(ctrl, &MandelbrotControleur::signalNouvelleLigne,
                [this](QList<FractalPoint> points) {
                    if(points.empty())
                        return;
                    pointsList_ << points;
                    emit signalUpdated();
                }
        );
        connect(ctrl, &MandelbrotControleur::signalCalculStoppe, this, &ThreadControleur::signalCalculStoppe); //Réémission du signal
        connect(ctrl, &MandelbrotControleur::signalCalculTermine, this, &ThreadControleur::onCalculTermine);
        connect(ctrl, &MandelbrotControleur::signalCalculTermine, th, &QThread::quit);
        connect(ctrl, &MandelbrotControleur::signalCalculStoppe, th, &QThread::quit);
        connect(th, &QThread::finished, th, &QThread::deleteLater);
        connect(th, &QThread::destroyed, ctrl, &MandelbrotControleur::deleteLater);
        th->start();
        th->setPriority(QThread::LowestPriority);

        int h = hauteur_/nbThreads_; //Il faudrait un nombre pair de threads...
        ctrl->calculeImage(largeur_, h, h*i, zoom_, iterations_, optimise_);
        emit signalCalculDemarre();
    }
}

void ThreadControleur::stoppeCalcul()
{
    qDebug() << "Stop calcul demandé";
    stoppe_ = true;
}

void ThreadControleur::onCalculTermine()
{
    qDebug() << "1 thread terminé";
    nbThreadsTermines_ += 1;
    if(nbThreadsTermines_ == nbThreads_) {
        qDebug() << "Calcul terminé, durée";
    }
}
