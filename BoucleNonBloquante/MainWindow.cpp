#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QDebug>
#include <QTimer>
#include <QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

static int ITERATIONS = 200;
void MainWindow::iteration() {
        qDebug() << "iteration_=" << iteration_;

        //Traitement long
        QByteArray b(10000, 'c');
        QByteArray c(10000, 0);
        for(int j = 0 ; j < b.size() ; j++) {
            QString s = QString::number(b[j]);
            s.append("un bout de chaine");
            c[j] = s.toLatin1()[5];
        }

        ui->progressBar->setValue(iteration_);

    if(iteration_++ < ITERATIONS) {
        QTimer::singleShot(0, this, SLOT(iteration()));
    } else {
        qDebug() << "Fin : " << QDateTime::currentMSecsSinceEpoch();
    }
}


void MainWindow::start()
{
    iteration_ = 0;
    qDebug() << "Début : " << QDateTime::currentMSecsSinceEpoch();
    ui->progressBar->setMaximum(ITERATIONS);
    ui->progressBar->setValue(0);
    QTimer::singleShot(0, this, SLOT(iteration()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    start();
}
