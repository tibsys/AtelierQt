#ifndef INSTANCE_H
#define INSTANCE_H

#include <QObject>
#include <QString>

class Instance : public QObject
{
    Q_OBJECT
public:
    explicit Instance(QString nom, QObject *parent = nullptr);
    ~Instance();

protected:
    QString nom_;
};

#endif // INSTANCE_H
