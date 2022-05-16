#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QTcpSocket>
#include <QTimer>
#include <QDateTime>
#include <QHostAddress>
#include <GpxHelper.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , socket_(new QTcpSocket(this))
    , timer_(new QTimer(this))
{
    ui->setupUi(this);
    ui->lblFrequenceDemandee->setText(QString::number(frequenceDemandee_));

    timer_->setSingleShot(false);
    timer_->setInterval(1000/frequenceDemandee_);
    ui->horizontalSlider->setValue(frequenceDemandee_);
    connect(timer_, &QTimer::timeout, this, &MainWindow::envoiTrame);

    connect(socket_, &QTcpSocket::disconnected, [=] {
        ui->console->append("Déconnecté du serveur");
        ui->pushButton->setEnabled(true);
        ui->pushButton_2->setEnabled(false);
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    ui->console->append(tr("Démarrage de la séquence"));
    QTimer::singleShot(0, this, &MainWindow::connectionAuServeur);
}

void MainWindow::connectionAuServeur()
{
    ui->console->append(tr("Tentative de connexion au serveur"));
    compteur_ = 1;

    socket_->connectToHost(QHostAddress::LocalHost, 8888);

    connect(socket_, &QTcpSocket::connected , this, [=] {
        ui->console->append(tr("Connexion effectuée... chargement des points"));
        points_ = GpxHelper::litFichier();
        ui->console->append(tr("Liste de points chargée... envoi des trames"));
        timer_->start();
        ui->pushButton->setEnabled(false);
        ui->pushButton_2->setEnabled(true);
    });
}

void MainWindow::envoiTrame()
{
    //Envoi d'une trame
    //On vide la liste progressivement, point après point
    if(points_.isEmpty()) {
        qWarning() << "Pas de point dans la liste";
        return;
    }
    QPair<float, float> point = points_.takeFirst();
    QString trame = QString("%1,%2\n").arg(point.second).arg(point.first);
    qDebug() << trame;
    socket_->write(trame.toLatin1());
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->lblFrequenceDemandee->setText(QString::number(value));
    frequenceDemandee_ = value;
    timer_->setInterval(1000/frequenceDemandee_);
}

void MainWindow::on_pushButton_2_clicked()
{
    ui->console->append("Arrêt de l'émission");
    timer_->stop();
    socket_->disconnectFromHost();
}
