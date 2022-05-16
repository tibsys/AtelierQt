#include "Lecteur.h"
#include <QTcpServer>
#include <QTcpSocket>

Lecteur::Lecteur()
    : server_(new QTcpServer(this))
{
    //-- code à insérer
    //Ici on faire en sorte de récupérer les données de la socket

    //-- code à insérer
    //Ici on ouvre la socket réseau

}

void Lecteur::onNouvelleTrame()
{
    qDebug() << "trame reçue, on avance";

    //-- code à insérer
    //Lecture des données depuis la socket

    //-- code à insérer
    //Décodage de la trame


    //-- code à insérer
    //Ici on envoie les points reçus
}
