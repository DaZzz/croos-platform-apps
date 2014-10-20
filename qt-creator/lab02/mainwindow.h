#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QAction>
#include <QMenu>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();
    ~MainWindow();

private:
    void createMenus();
    void createActions();

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *helpMenu;

    QAction *exitAction;
    QAction *setParamsAction;
    QAction *showAboutAction;

private slots:
    void showInputParamsDialog();
    void showAboutDialog();
};

#endif // MAINWINDOW_H
