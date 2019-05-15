#ifndef THREADCONTROLEUR_H
#define THREADCONTROLEUR_H

#include <QObject>
#include <QDebug>
#include "FractalPoint.h"

class ThreadControleur : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int threadsCount MEMBER nbThreads_)
    Q_PROPERTY(int zoom MEMBER zoom_)
    Q_PROPERTY(int iterations MEMBER iterations_)
    Q_PROPERTY(int largeur MEMBER largeur_)
    Q_PROPERTY(int hauteur MEMBER hauteur_)
    Q_PROPERTY(bool stoppe MEMBER stoppe_)
    Q_PROPERTY(bool optimise MEMBER optimise_)

public:
    explicit ThreadControleur(QObject *parent = nullptr);

signals:
    void signalNouveauPoint(FractalPoint point);    
    void signalUpdated();
    void signalCalculDemarre();
    void signalCalculTermine();
    void signalCalculStoppe();

public slots:
    void calculeImage();
    void stoppeCalcul();
    bool hasPoint() { return !pointsList_.empty(); }
    FractalPoint takeNextPoint() { return pointsList_.takeFirst(); }

private slots:
    void onCalculTermine();

private:
    int nbThreads_ = 0;
    int nbThreadsTermines_ = 0;
    int zoom_ = 0;
    int iterations_ = 0;
    int largeur_ = 0;
    int hauteur_ = 0;
    bool stoppe_ = false;
    bool optimise_ = false;
    QList<FractalPoint> pointsList_;
};

#endif // THREADCONTROLEUR_H
