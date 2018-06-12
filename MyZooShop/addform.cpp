#include "addform.h"
#include "storage.h"
#include "common.h"
#include "ui_addform.h"
#include <QtSql>
#include <QtWidgets>

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
//    connectDatabase addEntry;
//    addEntry.openConnection();

    if(ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()=="" || ui->doubleSpinBox->value()==0){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

//        //Write Query to database.
//        QSqlQuery writeQry;
//        //if(image=="")
//        writeQry.prepare("INSERT INTO animals (species,health,arrived,diet,notes,price,photo)"
//                         "VALUES(:species,:health,:arrived,:diet,:notice,:price,:photo);");

//        writeQry.bindValue(":species",ui->lineEdit_2->text());
//        writeQry.bindValue(":health",ui->lineEdit_3->text());
//        writeQry.bindValue(":arrived",ui->dateEdit->text());
//        writeQry.bindValue(":diet",ui->lineEdit_5->text());
//        writeQry.bindValue(":notice",ui->lineEdit_6->text());
//        writeQry.bindValue(":price",ui->doubleSpinBox->value());
//        writeQry.bindValue(":photo",image, QSql::In | QSql::Binary);

//        bool written = writeQry.exec();

//        if(written){
//            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
//        }
//        else{
//            QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
//        }
//        addEntry.closeConnection();
//     //Set the Lineedit to null to allow entry of new values.
//        ui->lineEdit_2->setText("");
//        ui->lineEdit_3->setText("");
//        ui->lineEdit_5->setText("");
//        ui->lineEdit_6->setText("");
//        ui->doubleSpinBox->setValue(0);
//    }
//    addEntry.closeConnection();


    /////////////////////////////////
    Storage storage;
    Animal ani(ui->lineEdit_2->text(),ui->dateEdit->text(),ui->lineEdit_3->text(),ui->lineEdit_5->text(),ui->lineEdit_6->text(),ui->doubleSpinBox->value(),image);
    if(storage.addAnimal(&ani)){
        QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
    }
    else{
       QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
    }
    ui->lineEdit_2->setText("");
            ui->lineEdit_3->setText("");
            ui->lineEdit_5->setText("");
            ui->lineEdit_6->setText("");
            ui->doubleSpinBox->setValue(0);
    }
}

void AddForm::on_pushButton_2_clicked()
{
    this->close();
}

void AddForm::on_pushButton_3_clicked()
{

    QString str=QFileDialog::getOpenFileName(this,tr("Load file"),"",tr("Image file(*.png *.jpg *.jpeg)"));
    QFile file(str);
         if (!file.open(QIODevice::ReadOnly)) return;
         QMessageBox::about(this,"Congrats!","Image loaded");
         QByteArray inByteArray = file.readAll();
//         QBuffer inBuffer( &inByteArray );
//             inBuffer.open( QIODevice::WriteOnly );
//             inPixmap.save( &inBuffer, "PNG" );
        image=inByteArray;

}
