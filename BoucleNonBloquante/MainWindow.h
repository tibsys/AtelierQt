#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void start();

private slots:
    void iteration();
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    int iteration_ = 0;
};

#endif // MAINWINDOW_H
