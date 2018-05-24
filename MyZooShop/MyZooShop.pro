#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:35:48
#
#-------------------------------------------------

QT       += core gui
QT += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyZooShop
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    autorisationwindow.cpp \
    login.cpp \
    adminwindow.cpp \
    sellerwindow.cpp \
    registerdialog.cpp \
    storage.cpp

HEADERS  += mainwindow.h \
    autorisationwindow.h \
    login.h \
    adminwindow.h \
    sellerwindow.h \
    registerdialog.h \
    storage.h

FORMS    += mainwindow.ui \
    autorisationwindow.ui \
    login.ui \
    adminwindow.ui \
    sellerwindow.ui \
    registerdialog.ui
