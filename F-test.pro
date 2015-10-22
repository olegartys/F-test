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

SOURCES += main.cpp\
        mainwindow.cpp \
    dragarea.cpp \
    selection.cpp \
    fishertablemodel.cpp


HEADERS  += mainwindow.h \
    dragarea.h \
    selection.h \
    fishertable.h \
    fishertablemodel.h


FORMS    += mainwindow.ui
