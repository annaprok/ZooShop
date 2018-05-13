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
    QString userName() const;
    QString password() const;
protected:
    void showEvent(QShowEvent * pEvent);
private:
    Ui::LogIn *ui;

    QLineEdit *m_ptxtUserName;
    QLineEdit *m_ptxtPassword;
};

#endif // LOGIN_H
