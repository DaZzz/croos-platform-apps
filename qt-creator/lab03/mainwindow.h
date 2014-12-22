#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "aboutdialog.h"
#include "mdichild.h"

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
    void closeAllWindows();

private:
    void setupActions();

    Ui::MainWindow *ui;
    AboutDialog *aboutDialog;
    QList<MdiChild *> mdiWindows;
};

#endif // MAINWINDOW_H
