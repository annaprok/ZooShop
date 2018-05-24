/********************************************************************************
** Form generated from reading UI file 'autorisationwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUTORISATIONWINDOW_H
#define UI_AUTORISATIONWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_autorisationWindow
{
public:
    QWidget *centralwidget;
    QPushButton *signUp_btn;
    QPushButton *logIn_btn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *autorisationWindow)
    {
        if (autorisationWindow->objectName().isEmpty())
            autorisationWindow->setObjectName(QStringLiteral("autorisationWindow"));
        autorisationWindow->resize(784, 491);
        centralwidget = new QWidget(autorisationWindow);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        signUp_btn = new QPushButton(centralwidget);
        signUp_btn->setObjectName(QStringLiteral("signUp_btn"));
        signUp_btn->setGeometry(QRect(90, 70, 120, 60));
        logIn_btn = new QPushButton(centralwidget);
        logIn_btn->setObjectName(QStringLiteral("logIn_btn"));
        logIn_btn->setGeometry(QRect(550, 70, 120, 60));
        autorisationWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(autorisationWindow);
        menubar->setObjectName(QStringLiteral("menubar"));
        menubar->setGeometry(QRect(0, 0, 784, 25));
        autorisationWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(autorisationWindow);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        autorisationWindow->setStatusBar(statusbar);

        retranslateUi(autorisationWindow);

        QMetaObject::connectSlotsByName(autorisationWindow);
    } // setupUi

    void retranslateUi(QMainWindow *autorisationWindow)
    {
        autorisationWindow->setWindowTitle(QApplication::translate("autorisationWindow", "MainWindow", 0));
        signUp_btn->setText(QApplication::translate("autorisationWindow", "Sign Up", 0));
        logIn_btn->setText(QApplication::translate("autorisationWindow", "Log In", 0));
    } // retranslateUi

};

namespace Ui {
    class autorisationWindow: public Ui_autorisationWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUTORISATIONWINDOW_H
