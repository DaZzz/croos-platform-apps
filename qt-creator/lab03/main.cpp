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
    qDebug() << translator.load(QString("/Users/DaZzz/Developer/qt/qt-creator/lab03/lab03_") + locale + ".qm");
    qDebug() << a.installTranslator(&translator);

    MainWindow w;
    w.show();

    return a.exec();
}
