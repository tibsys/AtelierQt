#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QThread>
#include <QMessageBox>
#include <QTimer>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QTimer *lcdTimer = new QTimer(this);
    lcdTimer->setSingleShot(false);
    lcdTimer->setInterval(50);
    connect(lcdTimer, &QTimer::timeout, this, &MainWindow::onLcdTimerTimeout);
    lcdTimer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onLcdTimerTimeout() {
    ui->lcdNumber->display(ui->lcdNumber->intValue()+1);
}

void MainWindow::on_pushButton_clicked()
{
    ui->pushButton->setDisabled(true);
    QTimer::singleShot(5000, this, SLOT(onPauseEnded()));
}

void MainWindow::onPauseEnded() {
    QMessageBox::information(nullptr, "Test", "La pause est terminée ! Au boulot !", QMessageBox::Ok);
    ui->pushButton->setDisabled(false);
}
