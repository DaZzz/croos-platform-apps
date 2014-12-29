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

    canvas = new Canvas();
    canvas->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);

    ui->scrollArea->setBackgroundRole(QPalette::Dark);
    canvas->setBackgroundRole(QPalette::Light);

    QGridLayout *layout = new QGridLayout;
    layout->addWidget(canvas);
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
        canvas->setNewImage(*pcImage);
        canvas->repaint();
    }

}

void MainWindow::on_actionOpen_triggered()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Open File"),
                                                         "",
                                                         tr("Files (*.jpg *png)"));

    canvas->setNewImage(QImage(filePath));
    canvas->repaint();
}

void MainWindow::on_scharrButton_clicked()
{
    m_pThreadWork->startScharr(canvas->getImage());
}
