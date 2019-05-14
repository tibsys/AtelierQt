#ifndef CONTROLLEUR_H
#define CONTROLLEUR_H

#include <QObject>

class Controlleur : public QObject
{
    Q_OBJECT
public:
    explicit Controlleur(QObject *parent = 0);

    void start();

private slots:
    void onNouvelleValeur(uint);

private:
    int total_;
    int nbReponses_;
};

#endif // CONTROLLEUR_H
