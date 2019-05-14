#ifndef CONTROLEUR_H
#define CONTROLEUR_H

#include <QObject>
#include "Rectangle.h"

using namespace toto;

class Controleur : public QObject
{
    Q_OBJECT

public:
    explicit Controleur(QObject *parent = nullptr);

signals:
    void signalRectangle(Rectangle&);

public slots:
    void onSignalRectangle(Rectangle&);
    void start();
};


#endif // CONTROLEUR_H
