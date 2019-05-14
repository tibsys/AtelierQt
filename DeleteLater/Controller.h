#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include "Recepteur.h"

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void start1();
    void start2();
    void start3();

public slots:
    void onObjetDetruit();

private:
    QObject *obj_;
    Recepteur *recepteur_;
};

#endif // CONTROLLER_H
