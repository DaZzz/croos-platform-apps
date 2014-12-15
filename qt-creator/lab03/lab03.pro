#-------------------------------------------------
#
# Project created by QtCreator 2014-12-10T18:39:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab03
TEMPLATE = app



TARGET = release
TRANSLATIONS += lab03_en_US.ts
DEPENDPATH +=.
INCLUDEPATH +=.

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

macx: LIBS += -L$$PWD/../../../../../../usr/local/Cellar/libarchive/3.1.2/lib/ -larchive

INCLUDEPATH += $$PWD/../../../../../../usr/local/Cellar/libarchive/3.1.2/include
DEPENDPATH += $$PWD/../../../../../../usr/local/Cellar/libarchive/3.1.2/include
