#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "TableModel.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TableModel* model = new TableModel;
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;
}

