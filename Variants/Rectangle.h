#ifndef RECTANGLE_H
#define RECTANGLE_H

#include <QMetaType>
#include <QString>
#include <QObject>

class Rectangle : public QObject
{    
public:        
    virtual ~Rectangle() {}
    Rectangle(const Rectangle& orig) : QObject(), a(orig.a), s(orig.s) {}

    Rectangle(int _a, QString _s);
    int a = 10;
    QString s = QString("test");
};


#endif // RECTANGLE_H
