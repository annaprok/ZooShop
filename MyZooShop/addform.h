#ifndef ADDFORM_H
#define ADDFORM_H

#include <QWidget>
#include "editentryform.h"
#include "databaseconnection.h"
#include "removeentryform.h"

namespace Ui {
class AddForm;
}

class AddForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddForm(QWidget *parent = 0);
    ~AddForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    QByteArray image;
    Ui::AddForm *ui;
};

#endif // ADDFORM_H
