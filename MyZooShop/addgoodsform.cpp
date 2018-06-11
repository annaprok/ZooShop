#include "addgoodsform.h"
#include "addform.h"
#include "ui_addgoodsform.h"

AddGoodsForm::AddGoodsForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddGoodsForm)
{
    ui->setupUi(this);
}

AddGoodsForm::~AddGoodsForm()
{
    delete ui;
}

void AddGoodsForm::on_pushButton_clicked()
{
    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit_2->text()=="" || ui->lineEdit->text()=="" || ui->doubleSpinBox->value()==0){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;

        writeQry.prepare("INSERT INTO goods (category,name,price,amount,status,expdate)"
                         "VALUES(:category,:name,:price,:amount,:status,:expdate);");

        writeQry.bindValue(":category",ui->lineEdit->text());
        writeQry.bindValue(":name",ui->lineEdit_2->text());
        writeQry.bindValue(":price",ui->doubleSpinBox->value());
        writeQry.bindValue(":amount",ui->spinBox->value());
        writeQry.bindValue(":status",ui->lineEdit_3->text());
        writeQry.bindValue(":expdate",ui->dateEdit->text());

        bool written = writeQry.exec();

        if(written){
            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
        }
        else{
            QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
        }
        addEntry.closeConnection();
     //Set the Lineedit to null to allow entry of new values.
        ui->lineEdit->setText("");
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->spinBox->setValue(0);
        ui->doubleSpinBox->setValue(0);
    }
    addEntry.closeConnection();
}

void AddGoodsForm::on_pushButton_2_clicked()

{
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->spinBox->setValue(0);
    ui->doubleSpinBox->setValue(0);
    this->close();
}
