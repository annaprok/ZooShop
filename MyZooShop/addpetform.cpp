#include "addpetform.h"
#include "ui_addpetform.h"
#include "adminwindow.h"
#include <QtSql>
#include <QtWidgets>

AddPetForm::AddPetForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPetForm)
{
    ui->setupUi(this);
    ui->lineEdit_5->setVisible(false);
    ui->label_6->setVisible(false);
    ownerId=-1;
}

AddPetForm::~AddPetForm()
{
    delete ui;
}

void AddPetForm::on_pushButton_clicked()
{
    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit_2->text()=="" || ui->lineEdit_3->text()=="" ){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;
        //if(image=="")
        writeQry.prepare("INSERT INTO pets (species,name,owner,photo)"
                         "VALUES(:species,:name,:owner,:photo);");

        writeQry.bindValue(":species",ui->lineEdit_2->text());
        writeQry.bindValue(":name",ui->lineEdit_3->text());
        if(role==-1){
            QSqlQuery query1;
                query1.prepare( "SELECT MAX(id) from clients" );
                if( !query1.exec( ))
                        qDebug() << "Error getting image from table:\n" << query1.lastError();
                clientId=query1.value(0).toInt()+1;
                writeQry.bindValue(":owner",clientId);

        }
        else{
            writeQry.bindValue(":owner",ui->lineEdit_5->text());
        }
        writeQry.bindValue(":photo",image, QSql::In | QSql::Binary);

        bool written = writeQry.exec();

        if(written){
            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
        }
        else{
            QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
        }
        addEntry.closeConnection();
     //Set the Lineedit to null to allow entry of new values.
        ui->lineEdit_2->setText("");
        ui->lineEdit_3->setText("");

    }
    addEntry.closeConnection();
}

void AddPetForm::on_pushButton_2_clicked()
{
    this->close();
}

void AddPetForm::on_pushButton_3_clicked()
{
    QString str=QFileDialog::getOpenFileName(this,tr("Load file"),"",tr("Image file(*.png *.jpg *.jpeg)"));
    QFile file(str);
         if (!file.open(QIODevice::ReadOnly)) return;
         QMessageBox::about(this,"Congrats!","Image loaded");
         QByteArray inByteArray = file.readAll();
        image=inByteArray;
}
