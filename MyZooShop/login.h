#ifndef LOGIN_H
#define LOGIN_H

#include <QDialog>

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
    QString userName() const;
    QString password() const;
    QString user() const;
signals:
    void acceptLogin( QString& username, QString& password, int& indexNumber );
public slots:
    void slotAcceptLogin();

private slots:
    void AddDialog::on_pushButton_clicked();
    
    void AddDialog::onButtonSend();
    
    void on_login_edit_textChanged(const QString &arg1);
    
    void on_password_edit_textChanged(const QString &arg1);
    
private:
    Ui::LogIn *ui;

};

#endif // LOGIN_H
