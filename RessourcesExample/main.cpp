#include <QCoreApplication>
#include <QFile>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QFile f(":/dossier1/TOTO");
    f.open(QFile::ReadOnly);
    qDebug() << f.readAll();


    return a.exec();
}
