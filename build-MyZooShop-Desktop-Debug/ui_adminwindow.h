/********************************************************************************
** Form generated from reading UI file 'adminwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINWINDOW_H
#define UI_ADMINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableView>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AdminWindow
{
public:
    QAction *actionNew_Entry;
    QAction *actionEdit_Entry;
    QAction *actionExit;
    QAction *actionRemove_Entry;
    QAction *actionAbout_Developer;
    QAction *actionAbout_Qt;
    QWidget *centralWidget;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QLabel *label;
    QLineEdit *lineEdit;
    QTableView *tableView;
    QLabel *label_6;
    QLabel *label_7;
    QProgressBar *progressBar;
    QComboBox *comboBox_2;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuAbout;
    QMenu *menuEdit;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *AdminWindow)
    {
        if (AdminWindow->objectName().isEmpty())
            AdminWindow->setObjectName(QStringLiteral("AdminWindow"));
        AdminWindow->resize(758, 465);
        AdminWindow->setLayoutDirection(Qt::LeftToRight);
        actionNew_Entry = new QAction(AdminWindow);
        actionNew_Entry->setObjectName(QStringLiteral("actionNew_Entry"));
        QIcon icon;
        icon.addFile(QStringLiteral(":Icons/Misc-New-Database-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Entry->setIcon(icon);
        actionEdit_Entry = new QAction(AdminWindow);
        actionEdit_Entry->setObjectName(QStringLiteral("actionEdit_Entry"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":Icons/Pencil-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionEdit_Entry->setIcon(icon1);
        actionExit = new QAction(AdminWindow);
        actionExit->setObjectName(QStringLiteral("actionExit"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":Icons/Button-Close-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionExit->setIcon(icon2);
        actionRemove_Entry = new QAction(AdminWindow);
        actionRemove_Entry->setObjectName(QStringLiteral("actionRemove_Entry"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":Icons/database-remove-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRemove_Entry->setIcon(icon3);
        actionAbout_Developer = new QAction(AdminWindow);
        actionAbout_Developer->setObjectName(QStringLiteral("actionAbout_Developer"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":Icons/Very-Basic-About-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Developer->setIcon(icon4);
        actionAbout_Qt = new QAction(AdminWindow);
        actionAbout_Qt->setObjectName(QStringLiteral("actionAbout_Qt"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":Icons/QtProject-creator-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionAbout_Qt->setIcon(icon5);
        centralWidget = new QWidget(AdminWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(500, 90, 241, 31));
        comboBox->setEditable(false);
        pushButton = new QPushButton(centralWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(600, 130, 141, 41));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(550, 10, 161, 31));
        QFont font;
        font.setPointSize(14);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(500, 50, 241, 31));
        tableView = new QTableView(centralWidget);
        tableView->setObjectName(QStringLiteral("tableView"));
        tableView->setGeometry(QRect(10, 180, 731, 201));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(240, -20, 211, 91));
        label_6->setFont(font);
        label_6->setAlignment(Qt::AlignCenter);
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(390, 80, 101, 51));
        QFont font1;
        font1.setPointSize(12);
        label_7->setFont(font1);
        label_7->setAlignment(Qt::AlignCenter);
        progressBar = new QProgressBar(centralWidget);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setGeometry(QRect(100, 100, 118, 23));
        progressBar->setValue(24);
        comboBox_2 = new QComboBox(centralWidget);
        comboBox_2->setObjectName(QStringLiteral("comboBox_2"));
        comboBox_2->setGeometry(QRect(260, 120, 85, 27));
        AdminWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(AdminWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 758, 25));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuAbout = new QMenu(menuBar);
        menuAbout->setObjectName(QStringLiteral("menuAbout"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        AdminWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(AdminWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        AdminWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(AdminWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        AdminWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuAbout->menuAction());
        menuFile->addAction(actionNew_Entry);
        menuFile->addSeparator();
        menuFile->addAction(actionExit);
        menuAbout->addAction(actionAbout_Developer);
        menuAbout->addAction(actionAbout_Qt);
        menuEdit->addAction(actionEdit_Entry);
        menuEdit->addAction(actionRemove_Entry);
        mainToolBar->addAction(actionNew_Entry);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionEdit_Entry);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionRemove_Entry);

        retranslateUi(AdminWindow);

        QMetaObject::connectSlotsByName(AdminWindow);
    } // setupUi

    void retranslateUi(QMainWindow *AdminWindow)
    {
        AdminWindow->setWindowTitle(QApplication::translate("AdminWindow", "AdminWindow", 0));
        actionNew_Entry->setText(QApplication::translate("AdminWindow", "New Animal", 0));
        actionEdit_Entry->setText(QApplication::translate("AdminWindow", "Edit Animals", 0));
        actionExit->setText(QApplication::translate("AdminWindow", "Exit", 0));
        actionRemove_Entry->setText(QApplication::translate("AdminWindow", "Remove Animal", 0));
        actionAbout_Developer->setText(QApplication::translate("AdminWindow", "About ", 0));
        actionAbout_Qt->setText(QApplication::translate("AdminWindow", "About Qt", 0));
        comboBox->setCurrentText(QString());
        pushButton->setText(QApplication::translate("AdminWindow", "Search Entry", 0));
        label->setText(QApplication::translate("AdminWindow", "Search Box", 0));
        label_6->setText(QApplication::translate("AdminWindow", "Zoo Shop Management", 0));
        label_7->setText(QApplication::translate("AdminWindow", "Search By :", 0));
        menuFile->setTitle(QApplication::translate("AdminWindow", "File", 0));
        menuAbout->setTitle(QApplication::translate("AdminWindow", "About", 0));
        menuEdit->setTitle(QApplication::translate("AdminWindow", "Edit", 0));
    } // retranslateUi

};

namespace Ui {
    class AdminWindow: public Ui_AdminWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINWINDOW_H
