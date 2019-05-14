#include "Recepteur.h"
#include <QDebug>
#include <QTimer>

Recepteur::Recepteur(QObject *parent, QObject *obj)
    : QObject(parent), obj_(obj)
{

}

Recepteur::~Recepteur() {
    qDebug() << "Destruction du récepteur";
}

void Recepteur::start() {
    qDebug() << "Lancement du timer";
    QTimer::singleShot(2000, this, SLOT(onTimer()));    
}

void Recepteur::onTimer()
{
    qDebug() << "Adresse de l'objet : " << obj_;
    qDebug() << obj_->objectName();
    //Suicide... pas courant mais c'est pour l'exemple
    //delete this; //Dangereux
    this->deleteLater();
}
