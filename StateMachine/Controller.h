#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <QObject>
#include <QStateMachine>
#include <QState>
#include <QFinalState>
#include <QTimer>

class Controller : public QObject
{
    Q_OBJECT
public:
    explicit Controller(QObject *parent = nullptr);
    void start();

private slots:
    void onTraitementDemarre();
    void onEtape1();
    void onEtape2();
    void onEtape3();
    void onEtape4();
    void onTraitementTermine();

private:
    QStateMachine automate_;
    QState debut_;
    QState etape1_;
    QState etape2_;
    QState etape3_;
    QState etape4_;
    QState fin_;
    QTimer jeton_;
};

#endif // CONTROLLER_H
