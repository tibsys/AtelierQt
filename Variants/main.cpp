#include <QCoreApplication>
#include "Rectangle.h"
#include <QVariant>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //Compléter la déclaration de Rectangle pour permettre son utilisation dans un QVariant

    Rectangle r(1000, "Test de variant");
    r.setProperty("test", "valeur");
    QVariant v;    
    v.setValue(r);   

    Rectangle r2 = v.value<Rectangle>();
    qDebug() << "r2.a=" << r2.a;
    qDebug() << "r2.s=" << r2.s;
    qDebug() << "r2.test=" << r2.property("test");
}
