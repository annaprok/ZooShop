/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *labelUsername;
    QLabel *labelPassword;
    QLineEdit *editPassword;
    QLineEdit *UsernameEdit;
    QLabel *statusLabel;
    QPushButton *loginButton;
    QPushButton *clearButton;

    void setupUi(QDialog *LogIn)
    {
        if (LogIn->objectName().isEmpty())
            LogIn->setObjectName(QStringLiteral("LogIn"));
        LogIn->resize(400, 300);
        buttonBox = new QDialogButtonBox(LogIn);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        formLayoutWidget = new QWidget(LogIn);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(120, 70, 162, 80));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        labelUsername = new QLabel(formLayoutWidget);
        labelUsername->setObjectName(QStringLiteral("labelUsername"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUsername);

        labelPassword = new QLabel(formLayoutWidget);
        labelPassword->setObjectName(QStringLiteral("labelPassword"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        editPassword = new QLineEdit(formLayoutWidget);
        editPassword->setObjectName(QStringLiteral("editPassword"));
        editPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, editPassword);

        UsernameEdit = new QLineEdit(formLayoutWidget);
        UsernameEdit->setObjectName(QStringLiteral("UsernameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, UsernameEdit);

        statusLabel = new QLabel(LogIn);
        statusLabel->setObjectName(QStringLiteral("statusLabel"));
        statusLabel->setGeometry(QRect(20, 170, 261, 20));
        loginButton = new QPushButton(LogIn);
        loginButton->setObjectName(QStringLiteral("loginButton"));
        loginButton->setGeometry(QRect(300, 110, 99, 27));
        clearButton = new QPushButton(LogIn);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        clearButton->setGeometry(QRect(300, 150, 99, 27));

        retranslateUi(LogIn);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogIn, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogIn, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QDialog *LogIn)
    {
        LogIn->setWindowTitle(QApplication::translate("LogIn", "Dialog", 0));
        labelUsername->setText(QApplication::translate("LogIn", "Login", 0));
        labelPassword->setText(QApplication::translate("LogIn", "Password", 0));
        statusLabel->setText(QApplication::translate("LogIn", "status..", 0));
        loginButton->setText(QApplication::translate("LogIn", "Log In", 0));
        clearButton->setText(QApplication::translate("LogIn", "Clear", 0));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
