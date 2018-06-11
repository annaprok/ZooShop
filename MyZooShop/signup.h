#ifndef SIGNUP_H
#define SIGNUP_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include "md5.h"
#include <QMessageBox>

namespace Ui {
class SignUp;
}

class SignUp : public QDialog
{
    Q_OBJECT

public:
    int id;
    explicit SignUp(QWidget *parent = 0);
    ~SignUp();
     QString hashFunc(QString password);

private slots:
    void on_loginButton_clicked();

    void on_clearButton_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::SignUp *ui;
    QSqlDatabase MyDb;
};

#endif // SIGNUP_H
