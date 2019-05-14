#ifndef MANDELBROTCONTROLEUR_H
#define MANDELBROTCONTROLEUR_H

#include <QObject>
#include <QColor>
#include <QPoint>
#include <QMap>
#include <QDebug>
#include "FractalPoint.h"

class MandelbrotControleur : public QObject
{
    Q_OBJECT    

public:    
    explicit MandelbrotControleur(bool *stoppe = nullptr, QObject *parent = nullptr);
    void creePalette();

signals:
    void signalNouveauPoint(FractalPoint point);
    void signalCalculStoppe();
    void signalCalculTermine();

public slots:
    void calculeImage(int largeur, int hauteur, int offsetY, int zoom, int iterations);

private slots:
    void calculePointSuivant();

private:
    QList<FractalPoint> points_;
    bool* stoppe_ = nullptr;
    int x_;
    int y_;
    int largeur_;
    int hauteur_;
    bool noirEtBlanc_;
    int zoom_;
    int iterations_;
    int offsetY_;
    int nbCouleurs = 3*256;
    QList<QColor> palette_;
};

#endif // MANDELBROTCONTROLEUR_H
