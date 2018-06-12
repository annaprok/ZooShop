#ifndef EDITCLIENTFORM_H
#define EDITCLIENTFORM_H

#include <QWidget>

namespace Ui {
class EditClientForm;
}

class EditClientForm : public QWidget
{
    Q_OBJECT

public:
    int toEdit;
    explicit EditClientForm(QWidget *parent = 0);
    ~EditClientForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditClientForm *ui;
};

#endif // EDITCLIENTFORM_H
