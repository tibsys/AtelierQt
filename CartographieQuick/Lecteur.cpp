#include "Lecteur.h"
#include <QTcpServer>
#include <QTcpSocket>
#include <QPoint>

Lecteur::Lecteur()
    : server_(new QTcpServer(this))
{
    connect(server_, &QTcpServer::newConnection, [=] {
        QTcpSocket* client = server_->nextPendingConnection();
        connect(client, &QTcpSocket::readyRead, this, &Lecteur::onNouvelleTrame);
    });
    server_->listen(QHostAddress::LocalHost, 8888);
}

void Lecteur::onNouvelleTrame()
{
    qDebug() << "trame reçue, on avance";

    //Décodage du point : à compléter
    QPoint point;

    emit signalNouvelleTrame(point);
}
