#include "DialogPressePapier.h"
#include "ui_DialogPressePapier.h"

#include <QClipboard>

DialogPressePapier::DialogPressePapier(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogPressePapier)
{
    ui->setupUi(this);
}

DialogPressePapier::~DialogPressePapier()
{
    delete ui;
}

void DialogPressePapier::on_pushButton_clicked()
{
    ui->txtEditColler->setText(QApplication::clipboard()->text());
}

void DialogPressePapier::on_pushButton_2_clicked()
{
    QApplication::clipboard()->setText(ui->txtEditCopier->toPlainText());
}

