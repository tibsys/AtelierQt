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

private:
    QList<Point> p;
};

#endif // RECTANGLE_H
