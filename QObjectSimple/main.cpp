#include <QCoreApplication>
#include "Rectangle.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Rectangle rect;
    Rectangle rect2 = rect;

    return a.exec();
}
