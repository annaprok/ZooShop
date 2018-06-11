#include "removestaffform.h"
#include "ui_removestaffform.h"
#include "databaseconnection.h"

RemoveStaffForm::RemoveStaffForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RemoveStaffForm)
{
    ui->setupUi(this);
}

RemoveStaffForm::~RemoveStaffForm()
{
    delete ui;
}

void RemoveStaffForm::on_pushButton_clicked()
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
                removeQry.prepare("delete from staff where id = :isbn");
                removeQry.bindValue(":isbn",ui->lineEdit->text());
            }
            else if(ui->lineEdit_2->text() != ""){
                removeQry.prepare("delete from staff where surname = :name");
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

void RemoveStaffForm::on_pushButton_2_clicked()
{
    this->close();
}
