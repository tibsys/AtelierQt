#include "MandelbrotControleur.h"
#include "mandelbrot.h"
#include <QDebug>
#include <QTimer>

MandelbrotControleur::MandelbrotControleur(bool *stoppe, QObject *parent)
    : QObject(parent), stoppe_(stoppe), x_(0), y_(0), largeur_(0), hauteur_(0), noirEtBlanc_(false), offsetY_(0)
{
    palette_.reserve(N_COLORS);
    creePalette();
}

void MandelbrotControleur::creePalette()
{
    for(int i = 0 ; i < 256 ; i++) {
        palette_.insert(i, QColor::fromRgb(0, 0, i));             // Noir -> Bleu
        palette_.insert(i + 256, QColor::fromRgb(i, i, 255 - i)); // Bleu -> Jaune
        palette_.insert(i + 2*256, QColor::fromRgb(255, 255, i)); // jaune -> Blanc
    }
}

void MandelbrotControleur::calculeImage(int largeur, int hauteur, int offsetY, int zoom, int iterations, bool optimise)
{
    largeur_ = largeur;
    hauteur_ = hauteur;
    zoom_ = zoom;
    iterations_ = iterations;
    x_ = 0;
    offsetY_ = offsetY;
    optimise_ = optimise;

    qDebug() << "Traitement par " << (optimise ? "ligne" : "point");
    qDebug() << QString("Le calcul est lancé... x=%1, offsetY=%2, largeur=%3, hauteur=%4, zoom=%5, iterations=%6").arg(x_).arg(offsetY_).arg(largeur).arg(hauteur).arg(zoom).arg(iterations);

    QTimer::singleShot(1, this, SLOT(iteration()));
}

void MandelbrotControleur::iteration()
{
    int couleur = calculeCouleurPixel(x_, y_+offsetY_, zoom_, iterations_);
    QPoint p(x_, y_+offsetY_);
    QColor coule(0,0,0);

    if(noirEtBlanc_) {
        coule = QColor(couleur, couleur, couleur);
    } else {
        coule = palette_[couleur];
    }

    if(!optimise_) {
        //En mode non optimisé on envoie point par point
        emit signalNouveauPoint(FractalPoint(p, coule));
    } else {
        //En mode optimisé on envoie ligne par ligne
        ligneCourante_ << FractalPoint(p, coule);
    }

    x_ += 1;
    if(x_ >= largeur_) {
        x_ = 0; y_+= 1;
    }
    if(y_ < hauteur_) {
        if(!*stoppe_)
            //QTimer::singleShot(1, this, SLOT(iteration()));
            QMetaObject::invokeMethod(this, "iteration", Qt::QueuedConnection);
        else
            emit signalCalculStoppe();
    }

    if(x_ == largeur_-1 && y_ == hauteur_-1) {
        if(optimise_) {
            emit signalNouvelleLigne(ligneCourante_);
            ligneCourante_.clear();
        }
        emit signalCalculTermine();
    }
}
