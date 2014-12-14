#include "main-window.h"
#include <QApplication>
#include <archive.h>
#include <archive_entry.h>
#include <QtDebug>
#include <QFile>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
