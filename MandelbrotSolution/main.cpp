#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include <QQuickStyle>
#include <QSysInfo>
#include <QThread>
#include "MandelbrotControleur.h"
#include "FractalPoint.h"
#include "ThreadControleur.h"

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);    
    QGuiApplication app(argc, argv);
    app.thread()->setPriority(QThread::LowestPriority);

    qmlRegisterType<MandelbrotControleur>("Local", 1, 0, "MandelbrotControleur");
    qmlRegisterType<ThreadControleur>("Local", 1, 0, "ThreadControleur");
    qRegisterMetaType<FractalPoint>("FractalPoint");

    QQmlApplicationEngine engine;
    QQuickStyle::setStyle("Universal");

    //Approche très simpliste : si c'est iOs on affiche MainPhone
    //Sinon on affiche MainPC
    //Une approche plus rigoureuse tiendrait compte en plus du
    //paramètre taille de l'écran, résolution et densité pour
    //calculer un ratio et viser des groupes d'appareils
    if(QSysInfo::productType() == "ios" || QSysInfo::productType() == "android") {
        engine.load(QUrl(QStringLiteral("qrc:/MainPhone.qml")));
    } else {
        engine.load(QUrl(QStringLiteral("qrc:/MainPC.qml")));
    }
    if (engine.rootObjects().isEmpty())
        return -1;    

    return app.exec();
}
