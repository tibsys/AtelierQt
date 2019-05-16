#ifndef WIDGETGRAPHIC_H
#define WIDGETGRAPHIC_H

#include <QWidget>
#include <QPixmap>
#include <QPainter>
#include <QDebug>
#include "FractalPoint.h"

class WidgetGraphic : public QWidget
{
    Q_OBJECT
public:
    explicit WidgetGraphic(QWidget *parent = nullptr);

public:
    void clear();
    void addPoint(FractalPoint &point) {
        if(picture_.isNull()) {
            //Initialisation du buffer s'il ne l'est pas
            qDebug() << "Initialise buffer";
            picture_ = QPixmap(geometry().size());
        }
        //Nous utilisons la technique du double-buffering
        QPainter painter(&picture_);
        painter.setPen(point.getCouleur());
        painter.drawPoint(point.getPoint());
        painter.end();

        //Déclenchement de la mise à jour du widget
        update();
    }

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);

private:
    QPixmap picture_;
};

#endif // WIDGETGRAPHIC_H
