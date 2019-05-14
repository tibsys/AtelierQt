#ifndef MONTHREAD_H
#define MONTHREAD_H

#include <QObject>
#include <QThread>
#include <QDebug>

class MonWorker : public QObject
{
    Q_OBJECT
public:
    MonWorker(uint debut, uint fin,  QObject* parent = 0);
    ~MonWorker() { qDebug() << "Destruction du worker"; }

public slots:
    void start();
    void stop();

signals:
    void signalWorkerEnded(uint);

private:
    uint valeur_;
    uint debut_;
    uint fin_;
};

class MonThread : public QObject
{
    Q_OBJECT
public:
    explicit MonThread(uint debut, uint fin, QObject *parent = 0);
    
public slots:
    void start();
    void stop();

signals:
    void signalNouvelleValeur(uint);

private slots:
    void onWorkerEnded(uint);
    
private:
    uint debut_;
    uint fin_;
    QThread* thread_;
};

#endif // MONTHREAD_H
