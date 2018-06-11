#ifndef REMOVESTAFFFORM_H
#define REMOVESTAFFFORM_H

#include <QWidget>

namespace Ui {
class RemoveStaffForm;
}

class RemoveStaffForm : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveStaffForm(QWidget *parent = 0);
    ~RemoveStaffForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RemoveStaffForm *ui;
};

#endif // REMOVESTAFFFORM_H
