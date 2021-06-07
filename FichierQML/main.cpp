#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "FileController.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    //qml : import namespace version_majeure.version_mineure
    //C++ : qmlRegisterType<T>(namespace, version_majeure, version_mineure, nom_du_type_QML
    qmlRegisterType<FileController>("alefbet", 1, 1, "ChargeurDeFichier");

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
