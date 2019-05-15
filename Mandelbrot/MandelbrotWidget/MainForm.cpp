#include "MainForm.h"
#include "ui_MainForm.h"

MainForm::MainForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MainForm)
{
    ui->setupUi(this);

    ui->sliderZoom->setValue(200);
    ui->sliderIterations->setValue(50);
    ui->sliderThreads->setValue(1);
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

}

void MainForm::on_btnStop_clicked()
{

}
