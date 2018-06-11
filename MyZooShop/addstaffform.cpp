#include "addstaffform.h"
#include "ui_addstaffform.h"
#include "addform.h"

AddStaffForm::AddStaffForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddStaffForm)
{
    ui->setupUi(this);
}

AddStaffForm::~AddStaffForm()
{
    delete ui;
}

void AddStaffForm::on_pushButton_clicked()
{
    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()==""){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;

        writeQry.prepare("INSERT INTO staff (name,surname,position,hired)"
                         "VALUES(:name,:surname,:position,:hired);");

        writeQry.bindValue(":name",ui->lineEdit->text());
        writeQry.bindValue(":surname",ui->lineEdit_2->text());
        writeQry.bindValue(":position",ui->lineEdit_3->text());
        writeQry.bindValue(":hired",ui->dateEdit->text());

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
    }
    addEntry.closeConnection();
}

void AddStaffForm::on_pushButton_2_clicked()
{
    this->close();
}
