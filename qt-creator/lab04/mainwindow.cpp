#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    canvas = new Canvas();
    ui->centralWidget->layout()->addWidget(canvas);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openImage()
{
//    QString fileName = QFileDialog::getOpenFileName(this, tr("Open File"),
//                                                         "",
//                                                         tr("Files (*.jpg *png)"));


}
