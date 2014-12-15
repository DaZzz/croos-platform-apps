#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void openFile();
    void openAboutDialog();

private:
    void setupActions();

    Ui::MainWindow *ui;
    AboutDialog *aboutDialog;
};

#endif // MAINWINDOW_H
