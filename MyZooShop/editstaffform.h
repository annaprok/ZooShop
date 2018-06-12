#ifndef EDITSTAFFFORM_H
#define EDITSTAFFFORM_H

#include <QWidget>

namespace Ui {
class EditStaffForm;
}

class EditStaffForm : public QWidget
{
    Q_OBJECT

public:
    int toEdit;
    explicit EditStaffForm(QWidget *parent = 0);
    ~EditStaffForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditStaffForm *ui;
};

#endif // EDITSTAFFFORM_H
