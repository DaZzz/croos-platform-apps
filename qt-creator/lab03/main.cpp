#include "mainwindow.h"
#include <QApplication>
#include <QtDebug>
#include <QFile>
#include <QTranslator>

#include <archive.h>
#include <archive_entry.h>

int main(int argc, char *argv[])
{

    // Reading archive start
    struct archive *a;
    struct archive_entry *entry;
    int r;

    a = archive_read_new();
    archive_read_support_filter_all(a);
    archive_read_support_format_all(a);

    r = archive_read_open_filename(a, "/Users/DaZzz/Desktop/Archive.zip", 10240);

    if (r != ARCHIVE_OK)
        qDebug() << "Archive is not ok!";

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
      qDebug() << archive_entry_pathname(entry);
//      qDebug() << archive_entry_stat(entry)->st_size;
//      qDebug() << (QString::number(S_IFDIR, 8));
//      qDebug() << (QString::number(archive_entry_stat(entry)->st_mode));
      archive_read_data_skip(a);  // Note 2
    }
    // Reading archive end

    QApplication app(argc, argv);
    QString locale = QLocale::system().name();
    QTranslator translator;
    translator.load(QString("/Users/DaZzz/Developer/qt/qt-creator/lab03/lab03_") + locale + ".qm");
    app.installTranslator(&translator);

    MainWindow w;
    w.show();

    return app.exec();
}
