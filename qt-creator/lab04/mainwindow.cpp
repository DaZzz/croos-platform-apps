#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    canvas = new Canvas();
    canvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    canvas->setBackgroundRole(QPalette::Light);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(canvas);
    ui->scrollAreaWidgetContents->setLayout(layout);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         "",
                                                         tr("Files (*.jpg *png)"));

    canvas->setNewImage(QImage(filePath));
    canvas->repaint();
}

void MainWindow::on_pushButton_clicked()
{
    canvas->applySchar();
    canvas->repaint();
}
