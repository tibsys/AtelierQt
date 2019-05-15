#ifndef FRACTALPOINT_H
#define FRACTALPOINT_H

#include <QObject>
#include <QColor>
#include <QPoint>

class FractalPoint {//: public QObject {
    Q_GADGET
    Q_PROPERTY(QPoint point MEMBER point_)
    Q_PROPERTY(QColor couleur MEMBER couleur_)

public:
    FractalPoint() {}
    virtual ~FractalPoint() {}
    FractalPoint(QPoint p, QColor c) : point_(p), couleur_(c) {}
    FractalPoint(const FractalPoint& orig) : point_(orig.point_), couleur_(orig.couleur_) {}

private:
    QPoint point_;
    QColor couleur_;
};
Q_DECLARE_METATYPE(FractalPoint)

#endif // FRACTALPOINT_H
