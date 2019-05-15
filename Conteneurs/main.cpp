#include <QCoreApplication>
#include <QDebug>
#include <QList>
#include <QMap>
#include "Rectangle.h"

//Choisir ici le numéro du TP
#define TP 1

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qDebug() << "";
    qDebug() << "TP n°" << TP;
    qDebug() << "";

    Rectangle r;
    QList<Rectangle> l;
    l << r;

    //Accès ou ajout
#if(TP == 1)
    Rectangle r1 = l[0];    
#endif

#if(TP == 2)
    Rectangle r2 = l[1]; //Provoque un crash
#endif

#if(TP == 3)
    Rectangle r3 = l.at(1); //Provoque un crash
#endif

#if(TP == 4)
    Rectangle rr;
    qDebug() << "r : @" << &rr;
    l.insert(3, r);
#endif

#if(TP < 5)
    qDebug() << l;
#else
    QMap<int, Rectangle> m;
    m[0] = Rectangle(); //Inséré automatiquement
    Rectangle r1 = l[0];
    m.insert(3, r1);
    Rectangle r4 = m.value(3);
    int i = m.key(r4); //L'opérateur operator== doit être défini dans Rectangle

    qDebug() << "clés : " << m.keys();
    int i2 = m.firstKey();
    m.take(i2); //take() prend la clé et la valeur
    qDebug() << "clés après take() : " << m.keys();
#endif

}
