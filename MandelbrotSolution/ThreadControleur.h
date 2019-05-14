#ifndef THREADCONTROLEUR_H
#define THREADCONTROLEUR_H

#include <QObject>
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

public:
    explicit ThreadControleur(QObject *parent = nullptr);

signals:
    void signalNouveauPoint(FractalPoint point);
    void signalCalculDemarre();
    void signalCalculTermine();
    void signalCalculStoppe();

public slots:
    void calculeImage();
    void stoppeCalcul();

private slots:
    void onCalculTermine();

private:
    int nbThreads_;
    int nbThreadsTermines_;
    int zoom_;
    int iterations_;
    int largeur_;
    int hauteur_;
    bool stoppe_;
};

#endif // THREADCONTROLEUR_H
