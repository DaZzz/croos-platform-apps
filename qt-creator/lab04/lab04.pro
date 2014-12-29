#-------------------------------------------------
#
# Project created by QtCreator 2014-12-28T17:09:37
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

QMAKE_MACOSX_DEPLOYMENT_TARGET = 10.9

TARGET = lab04
TEMPLATE = app

SOURCES += main.cpp\
        mainwindow.cpp \
    canvas.cpp \
    workerthread.cpp

HEADERS  += mainwindow.h \
    canvas.h \
    workerthread.h

FORMS    += mainwindow.ui

LIBS += -L/usr/local/Cellar/opencv/2.4.9/lib/ \
    -lopencv_core.2.4.9 \
    -lopencv_highgui.2.4.9 \
    -lopencv_imgproc.2.4.9 \

INCLUDEPATH += /usr/local/Cellar/opencv/2.4.9/include
