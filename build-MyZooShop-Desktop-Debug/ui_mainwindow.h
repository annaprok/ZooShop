/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *login_btn;
    QPushButton *register_btn;
    QPushButton *showAniButton;
    QPushButton *showGoodsButton;
    QPushButton *showCustomersButton;
    QPushButton *showSellersButton;
    QTableView *tableView;
    QPushButton *selectButton;
    QComboBox *comboBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(956, 552);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        login_btn = new QPushButton(centralWidget);
        login_btn->setObjectName(QStringLiteral("login_btn"));
        login_btn->setGeometry(QRect(180, 10, 99, 27));
        register_btn = new QPushButton(centralWidget);
        register_btn->setObjectName(QStringLiteral("register_btn"));
        register_btn->setGeometry(QRect(50, 20, 99, 27));
        showAniButton = new QPushButton(centralWidget);
        showAniButton->setObjectName(QStringLiteral("showAniButton"));
        showAniButton->setGeometry(QRect(40, 100, 99, 27));
        showGoodsButton = new QPushButton(centralWidget);
        showGoodsButton->setObjectName(QStringLiteral("showGoodsButton"));
        showGoodsButton->setGeometry(QRect(150, 100, 99, 27));
        showCustomersButton = new QPushButton(centralWidget);
        showCustomersButton->setObjectName(QStringLiteral("showCustomersButton"));
        showCustomersButton->setGeometry(QRect(268, 100, 121, 27));
        showSellersButton = new QPushButton(centralWidget);
        showSellersButton->setObjectName(QStringLiteral("showSellersButton"));
        showSellersButton->setGeometry(QRect(140, 150, 99, 27));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(270, 250, 256, 192));
        selectButton = new QPushButton(centralWidget);
        selectButton->setObjectName(QStringLiteral("selectButton"));
        selectButton->setGeometry(QRect(280, 150, 99, 27));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(430, 150, 85, 27));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 956, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        login_btn->setText(QApplication::translate("MainWindow", "login", 0));
        register_btn->setText(QApplication::translate("MainWindow", "register", 0));
        showAniButton->setText(QApplication::translate("MainWindow", "Show animals", 0));
        showGoodsButton->setText(QApplication::translate("MainWindow", "Show goods", 0));
        showCustomersButton->setText(QApplication::translate("MainWindow", "Show customers", 0));
        showSellersButton->setText(QApplication::translate("MainWindow", "Show sellers", 0));
        selectButton->setText(QApplication::translate("MainWindow", "Select", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
