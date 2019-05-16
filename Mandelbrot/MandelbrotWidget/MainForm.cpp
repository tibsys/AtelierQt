#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm),
    threadControleur_(new ThreadControleur(this))
{
    ui->setupUi(this);

    ui->sliderZoom->setValue(200);
    ui->sliderIterations->setValue(50);
    ui->sliderThreads->setValue(1);

    connect(threadControleur_, &ThreadControleur::signalNouveauPoint, this, &MainForm::onNouveauPoint);
    connect(threadControleur_, &ThreadControleur::signalCalculDemarre, this, &MainForm::onCalculDemarre);
    connect(threadControleur_, &ThreadControleur::signalCalculStoppe, this, &MainForm::onCalculStoppe);
    connect(threadControleur_, &ThreadControleur::signalCalculTermine, this, &MainForm::onCalculTermine);
}

MainForm::~MainForm()
{
    delete ui;
}

void MainForm::on_sliderThreads_valueChanged(int value)
{
    ui->lblThreads->setText(QString::number(value));
}

void MainForm::on_sliderIterations_valueChanged(int value)
{
    ui->lblIterations->setText(QString::number(value));
}

void MainForm::on_sliderZoom_valueChanged(int value)
{
    ui->lblZoom->setText(QString::number(value));
}


void MainForm::on_btnStart_clicked()
{
    qDebug() << "Effacement de l'écran";
    ui->canvasPane->clear();

    threadControleur_->setProperty("threadsCount", ui->sliderThreads->value());
    threadControleur_->setProperty("zoom", ui->sliderZoom->value());
    threadControleur_->setProperty("iterations", ui->sliderIterations->value());
    threadControleur_->setProperty("largeur", width());
    threadControleur_->setProperty("hauteur", height());

    threadControleur_->calculeImage();
}

void MainForm::on_btnStop_clicked()
{
    threadControleur_->stoppeCalcul();
}

void MainForm::onNouveauPoint(FractalPoint point)
{
    ui->canvasPane->addPoint(point);
}

void MainForm::onCalculDemarre()
{
    qDebug() << "Le calcul est démarré";
}

void MainForm::onCalculStoppe()
{
    qDebug() << "Le calcul est arrêté";
}

void MainForm::onCalculTermine()
{
    qDebug() << "Le calcul est terminé";
}
