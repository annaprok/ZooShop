/********************************************************************************
** Form generated from reading UI file 'sellerwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELLERWINDOW_H
#define UI_SELLERWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SellerWindow
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *SellerWindow)
    {
        if (SellerWindow->objectName().isEmpty())
            SellerWindow->setObjectName(QStringLiteral("SellerWindow"));
        SellerWindow->resize(800, 600);
        menubar = new QMenuBar(SellerWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        SellerWindow->setMenuBar(menubar);
        centralwidget = new QWidget(SellerWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        SellerWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(SellerWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        SellerWindow->setStatusBar(statusbar);

        retranslateUi(SellerWindow);

        QMetaObject::connectSlotsByName(SellerWindow);
    } // setupUi

    void retranslateUi(QMainWindow *SellerWindow)
    {
        SellerWindow->setWindowTitle(QApplication::translate("SellerWindow", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class SellerWindow: public Ui_SellerWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELLERWINDOW_H
