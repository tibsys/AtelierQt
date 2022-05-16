#include "MainWindowDragDrop.h"
#include "ui_MainWindowDragDrop.h"

#include <QDebug>
#include <QDrag>
#include <QMimeData>
#include <QPixmap>
#include <QMessageBox>

MainWindowDragDrop::MainWindowDragDrop(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MainWindowDragDrop)
{
    ui->setupUi(this);

    setAcceptDrops(true);
}

MainWindowDragDrop::~MainWindowDragDrop()
{
    delete ui;
}

void MainWindowDragDrop::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton && ui->dragObjet->geometry().contains(event->pos())) {
        QDrag *drag = new QDrag(this);
        QMimeData *mimeData = new QMimeData;

        mimeData->setText("Objet draggé");
        drag->setMimeData(mimeData);
        drag->setPixmap(QPixmap(":/icones/logoENI"));

        Qt::DropAction dropAction = drag->exec();
    }
}

void MainWindowDragDrop::dragEnterEvent(QDragEnterEvent *event)
{    
    if (ui->dropObjet->geometry().contains(event->pos()))
    {
        ui->dropObjet->setStyleSheet("background-color: black; color: white;");
        event->acceptProposedAction();
    } else
        ui->dropObjet->setStyleSheet("background-color: blue; color: white;");
}

void MainWindowDragDrop::dropEvent(QDropEvent *event)
{    
    if (ui->dropObjet->geometry().contains(event->pos()))
    {
        event->acceptProposedAction();
        ui->dropObjet->setStyleSheet("background-color: black; color: white;");
        QMessageBox::information(this, "Drag and drop", "L'objet a été déposé au bon endroit !", QMessageBox::Ok);
    }
}
