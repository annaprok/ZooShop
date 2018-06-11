#ifndef ADDSTAFFFORM_H
#define ADDSTAFFFORM_H

#include <QWidget>

namespace Ui {
class AddStaffForm;
}

class AddStaffForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddStaffForm(QWidget *parent = 0);
    ~AddStaffForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddStaffForm *ui;
};

#endif // ADDSTAFFFORM_H
