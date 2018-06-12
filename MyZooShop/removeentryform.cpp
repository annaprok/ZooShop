#include "removeentryform.h"
#include "ui_removeentryform.h"
#include "databaseconnection.h"
#include "storage.h"
#include "common.h"

removeentryform::removeentryform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::removeentryform)
{
    ui->setupUi(this);
}

removeentryform::~removeentryform()
{
    delete ui;
}

void removeentryform::on_pushButton_2_clicked()
{
    this->close();
}

void removeentryform::on_pushButton_clicked()
{
    connectDatabase removeEntry;
    bool isRemoved;

    removeEntry.openConnection();

    if(!removeEntry.openConnection())
    {
        QMessageBox::about(this,"Database Connection Failed!","Failed to Connect to database.");
    }
    else{
//            QSqlQuery removeQry;
//            if(ui->lineEdit->text() == "" && ui->lineEdit_2->text() == "")
//            {
//            QMessageBox::about(this,"No Key or Specios of Animal Found.","Please Enter ID or Species of the Animal!");
//            }
 //           else if(ui->lineEdit->text() != ""){
//                removeQry.prepare("delete from animals where id = :isbn");
//                removeQry.bindValue(":isbn",ui->lineEdit->text());
//            }
//            else if(ui->lineEdit_2->text() != ""){
//                removeQry.prepare("delete from animals where species = :name");
//                removeQry.bindValue(":name",ui->lineEdit_2->text());

//            }

//            isRemoved =removeQry.exec();

//            if(isRemoved){
//                QMessageBox::about(this,"Removal Successful!","Entry Successfully Removed.");
//            }
//            else{
//                QMessageBox::about(this,"Removal Error.","Wrong Value or Type of Data! Please try again.");
//            }
//////////////////////////////////////////////////////////////
        Storage storage;

        if(storage.deleteAnimal(toRemove))
        {
             QMessageBox::about(this,"Removal Successful!","Entry Successfully Removed.");
        }
        else
        {
          QMessageBox::about(this,"Removal Error.","Wrong Value or Type of Data! Please try again.");
        }

   // ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    }
}
