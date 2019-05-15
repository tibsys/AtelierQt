#include <QApplication>
#include <QDebug>
#include <QSysInfo>
#include <QThread>
#include "MainForm.h"
#include "FractalPoint.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QApplication app(argc, argv);
    app.thread()->setPriority(QThread::LowestPriority);
    qRegisterMetaType<FractalPoint>("FractalPoint");

    MainForm form;
    form.show();

    return app.exec();
}
