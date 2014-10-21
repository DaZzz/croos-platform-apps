#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow()
{
    canvas = new Canvas;
    setCentralWidget(canvas);

    inputDialog = new InputDialog(this);
    QObject::connect(
                inputDialog, SIGNAL(pointsNumberChanged(int)),
                this, SLOT(setPointsNumber(int)));

    aboutDialog = new AboutDialog(this);

    createActions();
    createMenus();

    setWindowTitle(tr("Рисователь звездочек"));
    setMinimumSize(480, 320);
    resize(480, 320);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    exitAction = new QAction(tr("&Выйти"), this);
    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));

    setParamsAction = new QAction(tr("&Входные данные"), this);
    connect(setParamsAction, SIGNAL(triggered()), this, SLOT(showInputParamsDialog()));

    showAboutAction = new QAction(tr("&О программе"), this);
    connect(showAboutAction, SIGNAL(triggered()), this, SLOT(showAboutDialog()));
}

void MainWindow::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&Файл"));
    fileMenu->addAction(exitAction);

    editMenu = menuBar()->addMenu(tr("&Правка"));
    editMenu->addAction(setParamsAction);

    helpMenu = menuBar()->addMenu(tr("&Справка"));
    helpMenu->addAction(showAboutAction);
}

void MainWindow::showInputParamsDialog()
{
    inputDialog->exec();
}

void MainWindow::showAboutDialog()
{
    aboutDialog->exec();
}

void MainWindow::setPointsNumber(int newValue)
{
    canvas->setPointsNumber(newValue);
}
