#include "editstaffform.h"
#include "adminwindow.h"
#include "ui_editstaffform.h"

EditStaffForm::EditStaffForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditStaffForm)
{
    ui->setupUi(this);
}

EditStaffForm::~EditStaffForm()
{
    delete ui;
}

void EditStaffForm::on_pushButton_clicked()
{
    connectDatabase editDB;
    bool isCorrectEntry;

    editDB.openConnection();

    if(ui->lineEdit->text() == ""){
        QMessageBox::about(this,"No Key!","Please Enter № of the record to be updated!");
    }
    else{
            QSqlQuery editQry;


            if(ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "" && ui->lineEdit_4->text() == ""){
                QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
            }


            if(ui->lineEdit_4->text()!=""){
              editQry.prepare("update staff set position = :position where id = :isbn");
              editQry.bindValue(":position",ui->lineEdit_4->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_3->text()!=""){
              editQry.prepare("update staff set surname = :surname where id = :isbn");
              editQry.bindValue(":surname",ui->lineEdit_3->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_2->text()!=""){
              editQry.prepare("update staff set name = :newname where id = :isbn");
              editQry.bindValue(":newname",ui->lineEdit_2->text());
              editQry.bindValue(":isbn",ui->lineEdit->text());
              isCorrectEntry = editQry.exec();
            }


          {                                               //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update staff set hired = :hired where id = :isbn");
              editQry.bindValue(":hired",ui->dateEdit->text());
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

}

void EditStaffForm::on_pushButton_2_clicked()
{
    this->close();
}
