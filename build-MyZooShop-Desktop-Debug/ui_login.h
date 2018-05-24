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
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_LogIn
{
public:
    QDialogButtonBox *buttonBox;

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

        retranslateUi(LogIn);
        QObject::connect(buttonBox, SIGNAL(accepted()), LogIn, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), LogIn, SLOT(reject()));

        QMetaObject::connectSlotsByName(LogIn);
    } // setupUi

    void retranslateUi(QDialog *LogIn)
    {
        LogIn->setWindowTitle(QApplication::translate("LogIn", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class LogIn: public Ui_LogIn {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
