#include "Controller.h"
#include <QDebug>

Controller::Controller(QObject *parent) : QObject(parent)
{}

void Controller::start()
{
    qDebug() << "Initialisation de l'automate";
    automate_.addState(&debut_);
    automate_.addState(&etape1_);
    automate_.addState(&etape2_);
    automate_.addState(&etape3_);
    automate_.addState(&etape4_);
    automate_.addState(&fin_);
    automate_.setInitialState(&debut_);

    qDebug() << "Initialisation des états";
    connect(&debut_, &QState::entered, this, &Controller::onTraitementDemarre);
    connect(&etape1_, &QState::entered, this, &Controller::onEtape1);
    connect(&etape2_, &QState::entered, this, &Controller::onEtape2);
    connect(&etape3_, &QState::entered, this, &Controller::onEtape3);
    connect(&etape4_, &QState::entered, this, &Controller::onEtape4);
    connect(&fin_, &QState::entered, this, &Controller::onTraitementDemarre);

    qDebug() << "Initialisation du jeton";
    jeton_.setInterval(1);
    jeton_.setSingleShot(true);

    qDebug() << "Initialisation des transitions";
    debut_.addTransition(&jeton_, SIGNAL(timeout()), &etape1_);
    etape1_.addTransition(&jeton_, SIGNAL(timeout()), &etape2_);
    etape2_.addTransition(&jeton_, SIGNAL(timeout()), &etape3_);
    etape3_.addTransition(&jeton_, SIGNAL(timeout()), &etape4_);
    etape4_.addTransition(&jeton_, SIGNAL(timeout()), &fin_);

    connect(&fin_, &QState::entered, this, &Controller::onTraitementTermine);

    qDebug() << "Démarrage du traitement";
    automate_.start();
}

void Controller::onTraitementDemarre()
{
    qDebug() << "Traitement démarré";

    jeton_.start();
}

void Controller::onEtape1()
{
    qDebug() << "Etape 1";

    jeton_.start();
}

void Controller::onEtape2()
{
    qDebug() << "Etape 2";

    jeton_.start();
}

void Controller::onEtape3()
{
    qDebug() << "Etape 3";

    jeton_.start();
}

void Controller::onEtape4()
{
    qDebug() << "Etape 4";

    jeton_.start();
}

void Controller::onTraitementTermine()
{
    qDebug() << "Traitement terminé";
}
