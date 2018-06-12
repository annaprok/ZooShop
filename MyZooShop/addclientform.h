#ifndef ADDCLIENTFORM_H
#define ADDCLIENTFORM_H

#include <QWidget>
#include "editentryform.h"
#include "databaseconnection.h"
#include "removeentryform.h"
#include "addpetform.h"

namespace Ui {
class AddClientForm;
}

class AddClientForm : public QWidget
{
    Q_OBJECT

public:
    int role;
    int id;
    int clientId;
    explicit AddClientForm(QWidget *parent = 0);
    ~AddClientForm();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_checkBox_clicked(bool checked);

private:
    AddPetForm AddPet;
    Ui::AddClientForm *ui;
};

#endif // ADDCLIENTFORM_H
