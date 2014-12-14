#include <QDebug>
#include <QFileDialog>
#include <QMdiSubWindow>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "mdichild.h"
#include <QTextEdit>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    aboutDialog = new AboutDialog(this);

    MdiChild *child = new MdiChild;
    child->loadFile(QDir::currentPath());
    ui->mdiArea->addSubWindow(child);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Открыть архив"), "", tr("Файловый архив (*.*)"));


}

void MainWindow::openAboutDialog()
{
    aboutDialog->exec();
}

void MainWindow::setupActions()
{
    connect(ui->openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->showAboutAction, SIGNAL(triggered()), this, SLOT(openAboutDialog()));
}

//void MainWindow::createMdiChild()
//{
//    MdiChild *child = new MdiChild;
//    mdiArea->addSubWindow();

//    connect(child, SIGNAL(copyAvailable(bool)),
//            cutAct, SLOT(setEnabled(bool)));
//    connect(child, SIGNAL(copyAvailable(bool)),
//            copyAct, SLOT(setEnabled(bool)));

//    return child;
//}
