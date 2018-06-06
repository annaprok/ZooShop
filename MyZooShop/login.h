#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>
#include <QtSql>
#include <QFileInfo>
#include <QDebug>
#include "md5.h"
#include <QMessageBox>


namespace Ui {
class LogIn;
}

class LogIn : public QDialog
{
    Q_OBJECT

public:
    explicit LogIn(QWidget *parent = 0);
    ~LogIn();
    void setUsername( QString& username );
    void setPassword( QString& password );
    void setUsernamesList( const QStringList& usernames );
    bool accepted;
    int role;
    QString userName() const;
    QString password() const;
    QString user() const;
    QString hashFunc(QString password);
signals:
    void acceptLogin( QString username, QString password, int role );
    void rejectLog();
public slots:
   // void slotAcceptLogin(QString username, QString password, int role);

private slots:
//    void AddDialog::on_pushButton_clicked();
    
//    void AddDialog::onButtonSend();
    
//    void on_login_edit_textChanged(const QString &arg1);
    
//    void on_password_edit_textChanged(const QString &arg1);
    
    void on_clearButton_clicked();

    void on_loginButton_clicked();

private:
    Ui::LogIn *ui;
    QSqlDatabase MyDb;
};

#endif // LOGIN_H
