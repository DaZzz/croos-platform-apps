#-------------------------------------------------
#
# Project created by QtCreator 2014-12-10T18:39:05
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = lab03
TEMPLATE = app

LIBS += -L/usr/local/Cellar/libarchive/3.1.2/lib/ -larchive
INCLUDEPATH += /usr/local/Cellar/libarchive/3.1.2/include
DEPENDPATH += /usr/local/Cellar/libarchive/3.1.2/include

SOURCES += main.cpp \
    main-window.cpp

HEADERS  += \
    main-window.h

FORMS    += \
    main-window.ui
