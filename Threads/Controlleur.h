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
    void termineApplicationSiThreadsDetruits();

private:
    std::atomic<int> total_;
    std::atomic<int> nbReponses_;
    std::atomic<int> nbThreadsTermines_;
};

#endif // CONTROLLEUR_H
