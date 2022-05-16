#include "Widget.h"
#include "ui_Widget.h"
#include <QMouseEvent>
#include <QGraphicsEllipseItem>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    QGraphicsScene *scene = new QGraphicsScene(this);
    scene->setBackgroundBrush(Qt::black);

    //Création d'un cercle au bord blanc et fond rouge
    cercle_ = scene->addEllipse(QRectF(0.0, 0.0, 200.0, 200.0), QPen(Qt::white, 5), QBrush(Qt::red));

    ui->graphicsView->setScene(scene);
}

//Faites bouger le cercle avec les touches du clavier

Widget::~Widget()
{
    delete ui;
}

