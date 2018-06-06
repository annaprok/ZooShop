#include "adminwindow.h"
#include "ui_adminwindow.h"

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

    QStringList list=(QStringList()<<"Sellers"<<"Clients"<<"Animals"<<"Goods");
    ui->comboTables->addItems(list);
}

AdminWindow::~AdminWindow()
{
    delete ui;
}
void AdminWindow::on_actionNew_Entry_triggered()
{
    connectDatabase openConn;

 if(!openConn.openConnection()){
    QMessageBox::about(this,"Connection Status","Failed!");
 }
 else{
    addAnimal.show();

 }
}

void AdminWindow::on_pushButton_clicked()
{
    connectDatabase searchDB;
    searchDB.openConnection();

    if(!searchDB.openConnection()){
        QMessageBox::critical(this,"Database Error!","Error Connecting to Database! Please try again or Check Database.");
    }

    //Modeling for Table View.

    QSqlQueryModel* databaseModel = new QSqlQueryModel;

    //Sql Query Prepration

    QSqlQuery* databaseQuery = new QSqlQuery(searchDB.DB);

    //Search based on option

    if(ui->comboBox->currentText() == "ID"){

        databaseQuery->prepare("select *from animals where id = :id;");
        databaseQuery->bindValue(":id",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Species"){

        databaseQuery->prepare("select *from animals where species = :name;");
        databaseQuery->bindValue(":name",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Health"){

        databaseQuery->prepare("select *from animals where health = :health;");
        databaseQuery->bindValue(":health",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Arrived"){

        databaseQuery->prepare("select *from animals where arrived = :arrived;");
        databaseQuery->bindValue(":arrived",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Select"){

        databaseQuery->exec("select *from animals");
    }
    else if(ui->comboBox->currentText() == "Diet"){

        databaseQuery->prepare("select *from animals where diet = :diet;");
        databaseQuery->bindValue(":diet",ui->lineEdit->text());
        databaseQuery->exec();
    }
    else if(ui->comboBox->currentText() == "Price"){

        databaseQuery->prepare("select *from animals where price = :price;");
        databaseQuery->bindValue(":price",ui->lineEdit->text().toDouble());
        databaseQuery->exec();
    }


    databaseModel->setQuery(*databaseQuery);
    ui->tableView->setModel(databaseModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    searchDB.closeConnection();
}

void AdminWindow::on_actionEdit_Entry_triggered()
{
    editDBentry.show();
}

void AdminWindow::on_actionRemove_Entry_triggered()
{
    removeEntry.show();
}

void AdminWindow::on_actionAbout_Developer_triggered()
{
    QMessageBox::about(this,"Shop Management Software","Created by ");
}

void AdminWindow::on_actionAbout_Qt_triggered()
{
    QMessageBox::aboutQt(this,"About Qt");
}

void AdminWindow::on_actionExit_triggered()
{
    this->close();
}

void AdminWindow::on_pushButton_2_clicked()
{
    if(ui->comboBox->currentText() == "Sellers"){
        QStringList list=(QStringList()<<"Select"<<"ID"<<"Species"<<"Health"<<"Arrived"<<"Diet"<<"Price");
        ui->comboBox->addItems(list);
    }
    if(ui->comboBox->currentText() == "Clients"){
        QStringList list=(QStringList()<<"Select"<<"ID"<<"Species"<<"Health"<<"Arrived"<<"Diet"<<"Price");
        ui->comboBox->addItems(list);
    }
    if(ui->comboBox->currentText() == "Animals"){
        QStringList list=(QStringList()<<"Select"<<"ID"<<"Species"<<"Health"<<"Arrived"<<"Diet"<<"Price");
        ui->comboBox->addItems(list);
    }
    if(ui->comboBox->currentText() == "Goods"){
        QStringList list=(QStringList()<<"Select"<<"ID"<<"Species"<<"Health"<<"Arrived"<<"Diet"<<"Price");
        ui->comboBox->addItems(list);
    }

}
