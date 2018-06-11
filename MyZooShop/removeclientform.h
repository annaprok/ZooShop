#ifndef REMOVECLIENTFORM_H
#define REMOVECLIENTFORM_H

#include <QWidget>

namespace Ui {
class RemoveClientForm;
}

class RemoveClientForm : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveClientForm(QWidget *parent = 0);
    ~RemoveClientForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RemoveClientForm *ui;
};

#endif // REMOVECLIENTFORM_H
