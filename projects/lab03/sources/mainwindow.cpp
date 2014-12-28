#include <QDebug>
#include <QFileDialog>
#include <QMdiSubWindow>
#include <QTextEdit>
#include <QtWidgets>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "aboutdialog.h"
#include "mdichild.h"

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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                     "",
                                                     tr("Files (*.zip)"));
    ui->windowsMenu->addAction(fileName);

    QAction *a = new QAction(fileName, ui->fileMenu);
    ui->fileMenu->insertAction(a, ui->fileMenu->actions().last());

    MdiChild *child = new MdiChild(fileName);
    mdiWindows.append(child);

    ui->mdiArea->addSubWindow(child);
    child->show();
    child->parentWidget()->resize(500, 500);
}

void MainWindow::openAboutDialog()
{
    aboutDialog->exec();
}

void MainWindow::closeAllWindows()
{
    ui->mdiArea->closeAllSubWindows();
}

void MainWindow::setupActions()
{
    connect(ui->openFileAction, SIGNAL(triggered()), this, SLOT(openFile()));
    connect(ui->showAboutAction, SIGNAL(triggered()), this, SLOT(openAboutDialog()));
    connect(ui->closeAllWindowsAction, SIGNAL(triggered()), this, SLOT(closeAllWindows()));
}

