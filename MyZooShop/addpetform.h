#ifndef ADDPETFORM_H
#define ADDPETFORM_H

#include <QWidget>

namespace Ui {
class AddPetForm;
}

class AddPetForm : public QWidget
{
    Q_OBJECT

public:
    int ownerId;
    int clientId;
    int role;
    explicit AddPetForm(QWidget *parent = 0);
    ~AddPetForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::AddPetForm *ui;

    QByteArray image;
};

#endif // ADDPETFORM_H
