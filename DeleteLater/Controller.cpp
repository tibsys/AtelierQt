#include "Controller.h"
#include <QTimer>
#include <QDebug>
#include <QThread>

Controller::Controller(QObject *parent)
    : QObject(parent), obj_(new QObject(this)), recepteur_(new Recepteur(this, obj_))
{
    obj_->setObjectName("toto");
}

void Controller::start1() {
    qDebug() << "Essai 1 : on détruit le récepteur tout de suite";
    recepteur_->start();
    delete obj_;
}

void Controller::start2() {
    qDebug() << "Essai 2 : on détruit le récepteur lors du prochain cycle de la run-loop";
    recepteur_->start();    
}

void Controller::start3() {
    qDebug() << "Essai 2 : on cycle les destructions";
    connect(recepteur_, &Recepteur::destroyed, obj_, &QObject::deleteLater);
    connect(obj_, &QObject::destroyed, this, &Controller::onObjetDetruit);
    recepteur_->start();
}

void Controller::onObjetDetruit() {
    qDebug() << "L'objet " << QObject::sender() << " va être détruit";
}
