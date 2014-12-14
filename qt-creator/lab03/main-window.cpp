#include <QDebug>
#include <QFileDialog>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    aboutDialog = new AboutDialog(this);

    setupActions();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString fileName = QFileDialog::getOpenFileName(this,
         tr("Открыть архив"), "", tr("Файловый архив (*.zip)"));

}

void MainWindow::openAboutDialog()
{
    aboutDialog->exec();
}

void MainWindow::setupActions()
{
    QAction *openFileAction = this->ui->openFileAction;
    connect(openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));

    QAction *showAboutAction = this->ui->showAboutAction;
    connect(showAboutAction, SIGNAL(triggered()), this, SLOT(openAboutDialog()));
}
