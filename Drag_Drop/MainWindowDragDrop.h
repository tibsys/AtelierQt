#ifndef MAINWINDOWDRAGDROP_H
#define MAINWINDOWDRAGDROP_H

#include <QDialog>
#include <QMouseEvent>
#include <QDropEvent>
#include <QDragEnterEvent>

namespace Ui {
class MainWindowDragDrop;
}

class MainWindowDragDrop : public QDialog
{
    Q_OBJECT

public:
    explicit MainWindowDragDrop(QWidget *parent = 0);
    ~MainWindowDragDrop();

public slots:
    void mousePressEvent(QMouseEvent *);
    void dragEnterEvent(QDragEnterEvent *);
    void dropEvent(QDropEvent *);

private:
    Ui::MainWindowDragDrop *ui;
};

#endif // MAINWINDOWDRAGDROP_H
