#include "MainWindowDragDrop.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindowDragDrop w;
    w.show();

    return a.exec();
}
