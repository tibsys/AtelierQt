#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QMap>
#include "Rectangle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Rectangle r;
    QList<Rectangle> l;
    l << r;

    //Accès ou ajout
    Rectangle r1 = l[0];
    //Rectangle r2 = l[1]; //Provoque un crash
    //Rectangle r3 = l.at(1); //Provoque un crash
    l.insert(3, Rectangle());

    QMap<int, Rectangle> m;
    m[0] = Rectangle(); //Inséré automatiquement
    m.insert(3, r1);
    Rectangle r4 = m.value(3);
    //int i = m.key(r4); //L'opérateur operator== doit être défini dans Rectangle

    qDebug() << m.keys();
    int i2 = m.firstKey();
    m.take(i2); //take() prend la clé et la valeur
    qDebug() << m.keys();

}
