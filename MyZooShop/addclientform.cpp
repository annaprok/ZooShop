#include "addclientform.h"
#include "ui_addclientform.h"

AddClientForm::AddClientForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddClientForm)
{
    ui->setupUi(this);

}

AddClientForm::~AddClientForm()
{
    delete ui;
}


void AddClientForm::on_pushButton_3_clicked()
{

    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit->text()=="" ){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;
        writeQry.bindValue(":telephone",ui->newEdit->text());
        // Get image data back from database
        query1.prepare( "SELECT id from users where login = :login and password_hash = :pass and role =-1" );
        query1.bindValue( ":id", imgId );
        query1.bindValue(":login",name);
        query1.bindValue(":pass", password);
        if( !query1.exec( ))
                qDebug() << "Error getting image from table:\n" << query1.lastError();
        int userId=querry1.value(0).toInteger();

        writeQry.prepare("insert into clients (name,added,telephone,address,userid) values(:name,:added,:telephone,:address,:userid);");
        writeQry.bindValue(":name",ui->lineEdit->text());
        writeQry.bindValue(":added",ui->dateEdit->text());
        writeQry.bindValue(":address",ui->lineEdit_3->text());
        //writeQry.bindValue(":animals",ui->lineEdit_4->text());
        writeQry.bindValue(":telephone",ui->newEdit->text());
        writeQry.bindValue(":telephone",id);

        bool written = writeQry.exec();

        if(written){
            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
        }
        else{
            QMessageBox::about(this,"Error Updating.","Error Updating Database! Check Connection or values!");
        }
        addEntry.closeConnection();

        ui->lineEdit->setText("");      //Set the Lineedit to null to allow entry of new values.
        ui->lineEdit_3->setText("");
       // ui->lineEdit_4->setText("");
        ui->newEdit->setText("");

    }
    addEntry.closeConnection();
}

void AddClientForm::on_pushButton_4_clicked()
{
    this->close();
}

void AddClientForm::on_pushButton_clicked()
{
     AddPet.role=role;
     if(role==-1)
      AddPet.ownerId=id;
    AddPet.show();
}
