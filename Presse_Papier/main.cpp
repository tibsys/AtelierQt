#include "DialogPressePapier.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    DialogPressePapier w;
    w.show();

    return a.exec();
}
