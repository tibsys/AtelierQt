#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QMenu>
#include <QAction>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    creeMenuContextuel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::creeMenuContextuel()
{
    //Créer un menu contextuel
    QAction *actionTerminer = new QAction(tr("Terminer"), this);
    actionTerminer->setShortcut(QKeySequence(Qt::CTRL | Qt::Key_T));
    connect(actionTerminer, &QAction::triggered, [] { //Connexion utilisant une fonction lambda
        qApp->quit();
    });
    menuFichiers_ = new QMenu(tr("Fichiers"), this);
    menuFichiers_->addAction(actionTerminer);
    ui->menubar->addMenu(menuFichiers_);

}

//Afficher le menu à l'emplacement du pointeur de la souris
//Le clic droit de la souris est capté grâce à un slot connecté
//au signal customContextMenuRequest(const QPoint&)



