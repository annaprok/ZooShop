#include "editclientform.h"
#include "adminwindow.h"
#include "ui_editclientform.h"

EditClientForm::EditClientForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditClientForm)
{
    ui->setupUi(this);
}

EditClientForm::~EditClientForm()
{
    delete ui;
}

void EditClientForm::on_pushButton_clicked()
{
    connectDatabase editDB;
    bool isCorrectEntry;

    editDB.openConnection();

    if(ui->lineEdit->text() == ""){
        QMessageBox::about(this,"No Key!","Please Enter № of the record to be updated!");
    }
    else{
            QSqlQuery editQry;


            if(ui->lineEdit_5->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "" && ui->lineEdit_4->text() == ""){
                QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
            }


            if(ui->lineEdit_4->text()!=""){
              editQry.prepare("update clients set animals = :animals where id = :isbn");
              editQry.bindValue(":animals",ui->lineEdit_4->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_3->text()!=""){
              editQry.prepare("update clients set address = :address where id = :isbn");
              editQry.bindValue(":address",ui->lineEdit_3->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_2->text()!=""){
              editQry.prepare("update clients set name = :newname where id = :isbn");
              editQry.bindValue(":newname",ui->lineEdit_2->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_5->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update clients set telephone = :telephone where id = :isbn");
              editQry.bindValue(":telephone",ui->lineEdit_5->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }
          {                                               //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update clients set date = :date where id = :isbn");
              editQry.bindValue(":date",ui->dateEdit->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

    }

    editDB.closeConnection();

    if(isCorrectEntry){
        QMessageBox::about(this,"Upation Successful","Entry Updated Successfully!");
    }
    else if (ui->lineEdit->text() != ""){
        QMessageBox::about(this,"Failed!","Error in Value or Input type!");
    }

    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

void EditClientForm::on_pushButton_2_clicked()
{
    this->close();
}
