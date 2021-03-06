#include "removeclientform.h"
#include "ui_removeclientform.h"
#include "databaseconnection.h"

RemoveClientForm::RemoveClientForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoveClientForm)
{
    ui->setupUi(this);
}

RemoveClientForm::~RemoveClientForm()
{
    delete ui;
}

void RemoveClientForm::on_pushButton_clicked()
{
    connectDatabase removeEntry;
    bool isRemoved;

    removeEntry.openConnection();

    if(!removeEntry.openConnection()){
        QMessageBox::about(this,"Database Connection Failed!","Failed to Connect to database.");
    }
    else{
            QSqlQuery removeQry;
            if(ui->lineEdit->text() == "" && ui->lineEdit_2->text() == ""){
            QMessageBox::about(this,"No Key or Specios of Animal Found.","Please Enter ID or Species of the Animal!");
            }
            else if(ui->lineEdit->text() != ""){
                removeQry.prepare("delete from clients where id = :isbn");
                removeQry.bindValue(":isbn",ui->lineEdit->text());
            }
            else if(ui->lineEdit_2->text() != ""){
                removeQry.prepare("delete from clients where name = :name");
                removeQry.bindValue(":name",ui->lineEdit_2->text());

            }

            isRemoved =removeQry.exec();

            if(isRemoved){
                QMessageBox::about(this,"Removal Successful!","Entry Successfully Removed.");
            }
            else{
                QMessageBox::about(this,"Removal Error.","Wrong Value or Type of Data! Please try again.");
            }
    }
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
}

void RemoveClientForm::on_pushButton_2_clicked()
{
    this->close();
}
