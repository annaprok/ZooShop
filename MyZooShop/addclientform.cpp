#include "addclientform.h"
#include "ui_addclientform.h"

AddClientForm::AddClientForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddClientForm)
{
    ui->setupUi(this);
    ui->formLayoutWidget->setVisible(false);

}

AddClientForm::~AddClientForm()
{
    delete ui;
}


void AddClientForm::on_pushButton_3_clicked()
{
    clientId=AddPet.clientId;
    connectDatabase addEntry;
    addEntry.openConnection();

    if(ui->lineEdit->text()=="" ){

            //Empty Feild throw error.
            QMessageBox::about(this,"Incomplete Entries!","Please Enter all the values to make an entry.");
    }
    else{

        //Write Query to database.
        QSqlQuery writeQry;

        //writeQry.bindValue(":telephone",ui->newEdit->text());
        // Get image data back from database


        writeQry.prepare("insert into clients (name,added,telephone,address,userid) values(:name,:added,:telephone,:address,:userid);");
        writeQry.bindValue(":name",ui->lineEdit->text());
        writeQry.bindValue(":added",ui->dateEdit->text());
        writeQry.bindValue(":address",ui->lineEdit_3->text());
        //writeQry.bindValue(":animals",ui->lineEdit_4->text());
        writeQry.bindValue(":telephone",ui->newEdit->text());
        if(role==-1)
        {
            writeQry.bindValue(":userid",id);
        }
        else
        {
            writeQry.bindValue(":userid",ui->lineEdit_2->text());
        }

        bool written = writeQry.exec();

        if(written)
        {
            QMessageBox::about(this,"Entry Updated!","Entry Updated to Database.");
        }
        else
        {
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

void AddClientForm::on_checkBox_clicked(bool checked)
{

       ui->formLayoutWidget->setVisible(checked);
    if(checked){
        if(role!=-1){
            ui->label_9->setVisible(false);
            ui->lineEdit_2->setVisible(false);
        }
    }
}
