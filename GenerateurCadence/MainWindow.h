#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class QTcpSocket;
class QTimer;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();
    void connectionAuServeur();
    void envoiTrame();
    void on_horizontalSlider_valueChanged(int value);
    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    QTcpSocket *socket_ = nullptr;
    QTimer* timer_ = nullptr;
    int frequenceDemandee_ = 1;
    int compteur_ = 1;
    QList<QPair<float, float>> points_;
};
#endif // MAINWINDOW_H
