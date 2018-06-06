#include "addform.h"
#include "ui_addform.h"

AddForm::AddForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddForm)
{
    ui->setupUi(this);
}

AddForm::~AddForm()
{
    delete ui;
}

void AddForm::on_pushButton_clicked()
{
    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit->text()=="" || ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()=="" || ui->doubleSpinBox->value()==0){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;

        writeQry.prepare("insert into animals values(:id,:species,:health,:arrived,:diet,:notice,:price);");
        writeQry.bindValue(":id",ui->lineEdit->text());
        writeQry.bindValue(":species",ui->lineEdit_2->text());
        writeQry.bindValue(":health",ui->lineEdit_3->text());
        writeQry.bindValue(":arrived",ui->lineEdit_4->text());
        writeQry.bindValue(":diet",ui->lineEdit_5->text());
        writeQry.bindValue(":notice",ui->lineEdit_6->text());
        writeQry.bindValue(":price",ui->doubleSpinBox->value());

        bool written = writeQry.exec();

        if(written){
            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
        }
        else{
            QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
        }
        addEntry.closeConnection();

        ui->lineEdit->setText("");      //Set the Lineedit to null to allow entry of new values.
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");
        ui->lineEdit_4->setText("");
        ui->lineEdit_5->setText("");
        ui->lineEdit_6->setText("");
        ui->doubleSpinBox->setValue(0);
    }
}

void AddForm::on_pushButton_2_clicked()
{
    this->close();
}
