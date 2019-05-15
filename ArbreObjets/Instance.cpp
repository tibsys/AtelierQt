#include "Instance.h"
#include <QDebug>

Instance::Instance(QString nom, QObject *parent) : QObject(parent), nom_(nom)
{
    qDebug() << "";
    qDebug() << "Création d'une nouvelle instance " << nom << " avec comme parent : " << parent;
    qDebug() << "  Adresse de la nouvelle instance : " << this;
    qDebug() << "";
}

Instance::~Instance() {
    qDebug() << "";
    qDebug() << "Destruction de l'instance " << nom_;

    if(parent() && QString::fromLatin1(parent()->metaObject()->className()) == "Instance") {
        qDebug() << "   Parent de l'instance : " << qobject_cast<Instance*>(parent())->nom_;
        qDebug() << "   Enfants de l'instance : " << children();
        foreach(QObject *child, children()) {
            qDebug() << "      " << qobject_cast<Instance*>(child)->nom_;
        }
    } else {
        qDebug() << "   Parent de l'instance : " << parent();
        qDebug() << "   Enfants de l'instance : " << children();
    }
}
