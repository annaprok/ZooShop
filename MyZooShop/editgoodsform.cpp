#include "editgoodsform.h"
#include "adminwindow.h"
#include "ui_editgoodsform.h"

EditGoodsForm::EditGoodsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::EditGoodsForm)
{
    ui->setupUi(this);
}

EditGoodsForm::~EditGoodsForm()
{
    delete ui;
}

void EditGoodsForm::on_pushButton_clicked()
{
    connectDatabase editDB;
    bool isCorrectEntry;

    editDB.openConnection();

    if(ui->lineEdit_4->text() == ""){
        QMessageBox::about(this,"No Key!","Please Enter № of the record to be updated!");
    }
    else{
            QSqlQuery editQry;


            if(ui->lineEdit->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == ""){
                QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
            }


            if(ui->lineEdit->text()!=""){
              editQry.prepare("update goods set name = :name where id = :isbn");
              editQry.bindValue(":name",ui->lineEdit->text());
              editQry.bindValue(":isbn",ui->lineEdit_4->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_3->text()!=""){
              editQry.prepare("update goods set status = :status where id = :isbn");
              editQry.bindValue(":status",ui->lineEdit_3->text());
              editQry.bindValue(":isbn",ui->lineEdit_4->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->lineEdit_2->text()!=""){
              editQry.prepare("update goods set category = :category where id = :isbn");
              editQry.bindValue(":category",ui->lineEdit_2->text());
              editQry.bindValue(":isbn",ui->lineEdit_4->text());
              isCorrectEntry = editQry.exec();
            }

            if(ui->doubleSpinBox->value()!=0){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update goods set price = :price where id = :isbn");
              editQry.bindValue(":price",ui->doubleSpinBox->value());
              editQry.bindValue(":isbn",ui->lineEdit_4->text());
              isCorrectEntry = editQry.exec();
            }
            if(ui->spinBox->value()!=0){                                               //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
              editQry.prepare("update goods set amount = :amount where id = :isbn");
              editQry.bindValue(":amount",ui->spinBox->value());
              editQry.bindValue(":isbn",ui->lineEdit_4->text());
              isCorrectEntry = editQry.exec();
            }
            {                                               //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
                          editQry.prepare("update goods set expdate = :expdate where id = :isbn");
                          editQry.bindValue(":expdate",ui->dateEdit->text());
                          editQry.bindValue(":isbn",ui->lineEdit_4->text());
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
    ui->doubleSpinBox->setValue(0);
    ui->spinBox->setValue(0);
}

void EditGoodsForm::on_pushButton_2_clicked()
{
    this->close();
}
