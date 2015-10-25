#-------------------------------------------------
#
# Project created by QtCreator 2015-10-15T16:28:41
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = untitled
TEMPLATE = app
CONFIG += c++11

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/dragarea.cpp \
    src/selection.cpp \
    src/fishertablemodel.cpp


HEADERS  += src/mainwindow.h \
    src/dragarea.h \
    src/selection.h \
    src/fishertable.h \
    src/fishertablemodel.h


FORMS    += src/mainwindow.ui

