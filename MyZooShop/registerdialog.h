#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>

typedef struct RegisterData{
    QString login;
    QString passworg;
}RegisterData;

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = 0);
    ~RegisterDialog();

private:
    Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
