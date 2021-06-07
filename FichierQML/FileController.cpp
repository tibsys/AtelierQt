#include "FileController.h"
#include <QUrl>
#include <QDebug>
#include <QFile>

FileController::FileController(QObject *parent) : QObject(parent)
{

}

QString FileController::readFile(QUrl url)
{
    qDebug() << "Lecture du fichier " << url;

    QFile f(url.toLocalFile());
    if(f.open(QFile::ReadOnly)) {
        qDebug() << "Le fichier a été lu";
        return f.readAll();
    }

    //Code arbitraire
    std::string s;

    //appels de libs externes...
    //C
    //python

    QString::fromStdString(s);

    qDebug() << "Le fichier n'a pas été lu";
    return QByteArray();
}
