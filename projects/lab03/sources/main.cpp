#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTranslator>

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);

    QString locale = QLocale::system().name();
    QTranslator translator;
    qDebug() << locale;
    qDebug() << translator.load("lab03_en_US");
    a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
