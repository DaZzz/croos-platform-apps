#include "mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow()
{
    canvas = new Canvas;
    setCentralWidget(canvas);

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

    showAboutAction = new QAction(tr("&Справка"), this);
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
    QMessageBox::warning(0,"Warning", tr("Здесь будет диалог «Входные данные»!"));
}

void MainWindow::showAboutDialog()
{
    QMessageBox::warning(0,"Warning", tr("Здесь будет диалог «О программе»!"));
}
