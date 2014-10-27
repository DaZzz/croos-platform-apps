#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>
#include "canvas.h"
#include "inputdialog.h"
#include "aboutdialog.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    void createMenus();
    void createActions();
    void drawCircle(int x, int y, QPainter &painter);

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *exitAction;
    QAction *setParamsAction;
    QAction *showAboutAction;

    Canvas *canvas;
    InputDialog *inputDialog;
    AboutDialog *aboutDialog;

private slots:
    void showInputParamsDialog();
    void showAboutDialog();
    void setPointsNumber(int newValue);
};

#endif // MAINWINDOW_H
