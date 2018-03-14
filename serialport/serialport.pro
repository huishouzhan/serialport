#-------------------------------------------------
#
# Project created by QtCreator 2017-09-21T10:35:15
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = serialport
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    serial_setting.cpp

HEADERS  += mainwindow.h \
    serial_setting.h

FORMS    += \
    mainwindow.ui
