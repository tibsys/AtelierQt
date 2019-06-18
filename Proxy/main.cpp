#include <QCoreApplication>
#include <QList>
#include <QString>
#include <QDebug>
#include <QMap>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString s1("s1");
    QString s2("s2");
    QString s3("s3");

    qDebug() << "@s1=" << &s1;
    qDebug() << "@s1.constData() " << s1.constData();
    qDebug() << "@s1.data() " << s1.data();
    qDebug() << "@s2=" << &s2;
    qDebug() << "@s2.constData() " << s2.constData();
    qDebug() << "@s3=" << &s3;
    qDebug() << "@s3.constData() " << s3.constData();
    qDebug() << "";

    qDebug() << "Insertion dans la liste";
    QList<QString> liste;
    liste << s1 << s2 << s3;
    qDebug() << "";

    qDebug() << "@s1=" << &s1;
    qDebug() << "@s1.constData() " << s1.constData();
    qDebug() << "@s2=" << &s2;
    qDebug() << "@s2.constData() " << s2.constData();
    qDebug() << "@s3=" << &s3;
    qDebug() << "@s3.constData() " << s3.constData();
    qDebug() << "";

    qDebug() << "Modifiation des données de s1";
    s1.append("blah");
    qDebug() << "@s1=" << &s1;
    qDebug() << "@s1.constData() " << s1.constData();
    qDebug() << "";

    qDebug() << "Récupération d'une référence (_s1) sur s1 depuis la liste";
    QString &_s1 = liste[0];
    qDebug() << "@_s1=" << &_s1;
    qDebug() << "@_s1.constData() " << _s1.constData();
    qDebug() << "";

    qDebug() << "Copie de s1 par affectation";
    QString s1_2 = s1;
    qDebug() << "@s1_2=" << &s1_2;
    qDebug() << "@s1_2.constData() " << s1_2.constData();
    qDebug() << "";

    qDebug() << "Copie de s1 par instanciation";
    QString s1_3(s1);
    qDebug() << "@s1_3=" << &s1_3;
    qDebug() << "@s1_3.constData() " << s1_3.constData();
    qDebug() << "";
}
