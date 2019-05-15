#ifndef RECTANGLE_H
#define RECTANGLE_H
#include <QList>

class Point {
public:
    int x = 0;
    int y = 0;
    int h = 0;
    int w = 0;
};

class Rectangle
{
public:
    operator QString() const { return QString("Rectangle @0x%1").arg((quintptr)this, QT_POINTER_SIZE * 2, 16, QChar('0')); }

private:
    QList<Point> p;
};

#endif // RECTANGLE_H
