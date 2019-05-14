#ifndef EMETTEUR_H
#define EMETTEUR_H

#include <QObject>

class Emetteur : public QObject
{
    Q_OBJECT
public:
    explicit Emetteur(QObject *parent = nullptr);
    void emetSignal();

signals:
    void signalUnSignal();

public slots:
};

#endif // EMETTEUR_H
