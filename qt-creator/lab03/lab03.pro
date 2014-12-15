#-------------------------------------------------
#
# Project created by QtCreator 2014-12-10T18:39:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab03
TEMPLATE = app

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/Cellar/quazip/0.7/lib/release/ -lquazip
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/Cellar/quazip/0.7/lib/debug/ -lquazip
#else:unix: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/quazip/0.7/lib/ -lquazip

#INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/quazip/0.7/include
#DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/quazip/0.7/include

#win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/Cellar/zlib/1.2.8/lib/release/ -lz
#else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../../../../usr/local/Cellar/zlib/1.2.8/lib/debug/ -lz
#else:unix: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/zlib/1.2.8/lib/ -lz

#INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/zlib/1.2.8/include
#DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/zlib/1.2.8/include

#LIBS += -L/usr/local/Cellar/libarchive/3.1.2/lib/ -lquazip
#INCLUDEPATH += /usr/local/Cellar/libarchive/3.1.2/include
#DEPENDPATH += /usr/local/Cellar/libarchive/3.1.2/include

#LIBS += -L/usr/local/Cellar/zlib/1.2.8/ -lz
#INCLUDEPATH += /usr/local/Cellar/zlib/1.2.8/include
#DEPENDPATH += /usr/local/Cellar/zlib/1.2.8/include

#LIBS += -L/usr/local/Cellar/quazip/0.7/lib/ -lquazip
#INCLUDEPATH += /usr/local/Cellar/quazip/0.7/include
#DEPENDPATH += /usr/local/Cellar/quazip/0.7/include

TARGET = release
TRANSLATIONS += lab03_en_US.ts
DEPENDPATH +=.
INCLUDEPATH +=.

#macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/quazip/0.7/lib/ -lquazip
#INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/quazip/0.7/include
#DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/quazip/0.7/include



SOURCES += main.cpp\
        mainwindow.cpp \
    aboutdialog.cpp \
    mdichild.cpp \
    editablefilesystemmodel.cpp

HEADERS  += mainwindow.h \
    aboutdialog.h \
    mdichild.h \
    editablefilesystemmodel.h

FORMS    += mainwindow.ui \
    aboutdialog.ui

OTHER_FILES += \
    lab03_en_US.ts
