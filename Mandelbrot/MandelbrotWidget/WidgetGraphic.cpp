#include "WidgetGraphic.h"
#include <QDebug>

WidgetGraphic::WidgetGraphic(QWidget *parent) : QWidget(parent)
{

}

void WidgetGraphic::clear()
{
    qDebug() << "Effacement de l'écran";
    picture_ = QPixmap();
    update();
}

void WidgetGraphic::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    if(picture_.isNull()) {
        painter.setBrush(Qt::black);
        painter.drawRect(geometry());
    } else {
        painter.drawPixmap(geometry(), picture_, geometry());
    }

    painter.end();
}
