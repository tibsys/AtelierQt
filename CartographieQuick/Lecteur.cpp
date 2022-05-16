#include "Lecteur.h"
#include <QTcpServer>
#include <QTcpSocket>

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


    QTcpSocket* sender = qobject_cast<QTcpSocket*>(QObject::sender());
    if(sender == nullptr) {
        qWarning() << "Problème avec la socket";
        return;
    }

    //Décodage de la trame
    QByteArray data = sender->readLine();
    //qDebug() << "Ligne lue : " << data;
    QStringList split = QString::fromLatin1(data.trimmed()).split(",");
    if(split.size() != 2) {
        qWarning() << "Mauvais format de trame : " << split;
        return;
    }

    emit signalNouvelleTrame(QPointF(split[0].trimmed().toFloat(), split[1].trimmed().toFloat()));
}
