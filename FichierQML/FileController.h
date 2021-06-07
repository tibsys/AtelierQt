#ifndef FILECONTROLLER_H
#define FILECONTROLLER_H

#include <QObject>
#include <QUrl>

class FileController : public QObject
{
    Q_OBJECT
public:
    explicit FileController(QObject *parent = nullptr);

    Q_INVOKABLE QString readFile(QUrl url);

};

#endif // FILECONTROLLER_H
