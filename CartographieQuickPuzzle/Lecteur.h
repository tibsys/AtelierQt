#ifndef LECTEUR_H
#define LECTEUR_H

#include <QObject>
#include <QPointF>

class QTcpServer;

class Lecteur : public QObject
{
    Q_OBJECT

public:
    Lecteur();

signals:
    void signalNouvelleTrame(const QPointF gpsPoint);

private slots:
    void onNouvelleTrame();

private:
    QTcpServer *server_ = nullptr;
};

#endif // LECTEUR_H
