#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

static int ITERATIONS = 1000;
void MainWindow::start()
{
    qDebug() << "Début : " << QDateTime::currentMSecsSinceEpoch();

    ui->progressBar->setMaximum(ITERATIONS);
    ui->progressBar->setValue(0);
    for(int i = 0 ; i < ITERATIONS ; i++) {
        qDebug() << "i=" << i;

        //Traitement long
        QByteArray b(10000, 'c');
        QByteArray c(10000, 0);
        for(int j = 0 ; j < b.size() ; j++) {
            QString s = QString::number(b[j]);
            s.append("un bout de chaine");
            c[j] = s.toLatin1()[5];
        }

        ui->progressBar->setValue(i);
    }

    qDebug() << "Fin : " << QDateTime::currentMSecsSinceEpoch();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    ui->progressBar->setValue(0);
    start();
}
