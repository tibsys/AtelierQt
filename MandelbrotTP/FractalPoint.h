#ifndef FRACTALPOINT_H
#define FRACTALPOINT_H

#include <QObject>
#include <QColor>
#include <QPoint>
#include <QSharedData>
#include <QSharedDataPointer>

class FractalPointData : public QSharedData {
public:
    QPoint point;
    QColor couleur;
};

class FractalPoint {
    Q_GADGET //Version allégée de Q_OBJECT pour les classe n'héritant pas de QObject
    Q_PROPERTY(QPoint point READ point())
    Q_PROPERTY(QColor couleur READ couleur())

public:
    FractalPoint()
        : d_(new FractalPointData) {}

    virtual ~FractalPoint() {}

    FractalPoint(QPoint p, QColor c)
        : d_(new FractalPointData) {
        d_->point = p;
        d_->couleur = c;
    }

    QPoint point() const { return d_->point; }
    QColor couleur() const { return d_->couleur; }
    void setPoint(QPoint& p) { d_->point = p; }
    void setCouleur(QColor& c) { d_->couleur = c; }

    FractalPoint(const FractalPoint& orig) : d_(orig.d_) {}

private:
    QSharedDataPointer<FractalPointData> d_; //Partage implicite
};
Q_DECLARE_METATYPE(FractalPoint)

#endif // FRACTALPOINT_H
