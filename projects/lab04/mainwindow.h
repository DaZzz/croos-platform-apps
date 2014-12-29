#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "canvas.h"

class WorkerThread;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    Canvas *canvas;
    WorkerThread *m_pThreadWork;

private slots:
    void on_actionOpen_triggered();

    void onThreadStarted();
    void onThreadFinished();
    void on_scharrButton_clicked();
};

#endif // MAINWINDOW_H
