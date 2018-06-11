#-------------------------------------------------
#
# Project created by QtCreator 2018-05-13T13:35:48
#
#-------------------------------------------------

QT       += core gui
QT += core gui sql
QT       += core network
QT += widgets
QMAKE_CXXFLAGS += -std=c++0x

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MyZooShop
TEMPLATE = app
INCLUDEPATH+=/home/anna/workspace/projects/progbase2/labs/lab6/Common
LIBS +=-L/home/anna/workspace/projects/progbase2/labs/lab6/build-Common-Desktop-Debug -L. -lCommon -Wl,-rpath,/home/anna/workspace/projects/progbase2/labs/lab6/build-Common-Desktop-Debug -Wl,-rpath,.


SOURCES += main.cpp\
        mainwindow.cpp \
    autorisationwindow.cpp \
    login.cpp \
    adminwindow.cpp \
    sellerwindow.cpp \
    registerdialog.cpp \
    storage.cpp \
    md5.cpp \
    client.cpp \
    dbmanager.cpp \
    removeentryform.cpp \
    editentryform.cpp \
    addform.cpp \
    signup.cpp \
    userwindow.cpp \
    addclientform.cpp \
    addstaffform.cpp \
    addgoodsform.cpp \
    editclientform.cpp \
    editgoodsform.cpp \
    editstaffform.cpp \
    removeclientform.cpp \
    removegoodsform.cpp \
    removestaffform.cpp \
    addpetform.cpp

HEADERS  += mainwindow.h \
    autorisationwindow.h \
    login.h \
    adminwindow.h \
    sellerwindow.h \
    registerdialog.h \
    storage.h \
    md5.h \
    common.h \
    common_global.h \
    client.h \
    dbmanager.h \
    removeentryform.h \
    editentryform.h \
    databaseconnection.h \
    addform.h \
    signup.h \
    userwindow.h \
    addclientform.h \
    addstaffform.h \
    addgoodsform.h \
    editclientform.h \
    editgoodsform.h \
    editstaffform.h \
    removeclientform.h \
    removegoodsform.h \
    removestaffform.h \
    addpetform.h

FORMS    += mainwindow.ui \
    autorisationwindow.ui \
    login.ui \
    adminwindow.ui \
    sellerwindow.ui \
    registerdialog.ui \
    editentryform.ui \
    removeentryform.ui \
    addform.ui \
    signup.ui \
    userwindow.ui \
    addclientform.ui \
    addstaffform.ui \
    addgoodsform.ui \
    editclientform.ui \
    editgoodsform.ui \
    editstaffform.ui \
    removeclientform.ui \
    removegoodsform.ui \
    removestaffform.ui \
    addpetform.ui

RESOURCES += \
    shopmanagementresources.qrc
