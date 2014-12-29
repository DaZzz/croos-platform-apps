#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "canvas.h"
#include <QFileDialog>
#include <QDebug>
#include "workerthread.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->scrollArea->setBackgroundRole(QPalette::Dark);

    m_pCanvas = new Canvas();
    m_pCanvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    m_pCanvas->setBackgroundRole(QPalette::Light);


    QGridLayout *layout = new QGridLayout;
    layout->addWidget(m_pCanvas);
    ui->scrollAreaWidgetContents->setLayout(layout);

    m_pThreadWork = new WorkerThread(this);
    connect(
        m_pThreadWork, SIGNAL(started()),
        this, SLOT(onThreadStarted()));
      connect(
        m_pThreadWork, SIGNAL(finished()),
        this, SLOT(onThreadFinished()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onThreadStarted()
{
    ui->scharrButton->setEnabled(false);
}

void MainWindow::onThreadFinished()
{
    ui->scharrButton->setEnabled(true);
    const QImage *pcImage = m_pThreadWork->getResultImage();
    if (pcImage)
    {
        m_pCanvas->setNewImage(*pcImage);
        m_pCanvas->repaint();
    }

}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         "",
                                                         tr("Files (*.jpg *.jpeg *.png)"));

    m_pCanvas->setNewImage(QImage(filePath));
    m_pCanvas->repaint();
}

void MainWindow::on_scharrButton_clicked()
{
    m_pThreadWork->startScharr(m_pCanvas->getImage());
}
