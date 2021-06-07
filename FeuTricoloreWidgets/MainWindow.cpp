#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    allumeFeuVert();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::allumeFeuRouge()
{
    ui->feuRouge->setStyleSheet("background-color: red;");
    ui->feuOrange->setStyleSheet("background-color: transparent;");
    ui->feuVert->setStyleSheet("background-color: transparent;");

    QTimer::singleShot(2000, this, &MainWindow::allumeFeuVert);
}

void MainWindow::allumeFeuOrange()
{
    ui->feuRouge->setStyleSheet("background-color: transparent;");
    ui->feuOrange->setStyleSheet("background-color: orange;");
    ui->feuVert->setStyleSheet("background-color: transparent;");

    QTimer::singleShot(3000, this, &MainWindow::allumeFeuRouge);
}

void MainWindow::allumeFeuVert()
{
    ui->feuRouge->setStyleSheet("background-color: transparent;");
    ui->feuOrange->setStyleSheet("background-color: transparent;");
    ui->feuVert->setStyleSheet("background-color: green;");

    QTimer::singleShot(2000, this, &MainWindow::allumeFeuOrange);
}

