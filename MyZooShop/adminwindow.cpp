#include "adminwindow.h"
#include "ui_adminwindow.h"
#include <QtWidgets>

AdminWindow::AdminWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AdminWindow)
{
    ui->setupUi(this);

//    QStringList list=(QStringList()<<"Staff"<<"Clients"<<"Animals"<<"Goods");
//    ui->comboTables->addItems(list);
    ui->comboTables->setEnabled(false);
    ui->label_2->setVisible(false);
    ui->actionEdit_Entry->setVisible(false);
    ui->actionRemove_Entry->setVisible(false);
    ui->actionNew_Entry->setVisible(false);
    id=0;
    role=0;
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
     if(ui->comboTables->currentText()== "Animals")
        addAnimal.show();
     else if(ui->comboTables->currentText() == "Staff")
         AddStaff.show();
     else if(ui->comboTables->currentText() == "Clients")
         AddClient.show();
     else if(ui->comboTables->currentText() == "Goods")
         AddGoods.show();

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

    if(ui->comboBox->currentText() == "ID"&&ui->comboTables->currentText() == "Animals"){

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


    else if(ui->comboBox->currentText() == "Select"&&ui->comboTables->currentText() == "Animals"){

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
    /////////////////////

    else if(ui->comboBox->currentText() == "Select"&&ui->comboTables->currentText() == "Staff"){

        databaseQuery->exec("select *from staff");
    }
    else if(ui->comboBox->currentText() == "ID"&&ui->comboTables->currentText() == "Staff"){

        databaseQuery->prepare("select *from staff where id = :id;");
        databaseQuery->bindValue(":id",ui->lineEdit->text());
        databaseQuery->exec();
    }
    else if(ui->comboBox->currentText() == "Surname"){

        databaseQuery->prepare("select *from staff where surname = :surname;");
        databaseQuery->bindValue(":surname",ui->lineEdit->text());
        databaseQuery->exec();
    }

    else if(ui->comboBox->currentText() == "Name"){

        databaseQuery->prepare("select *from staff where name = :sname;");
        databaseQuery->bindValue(":sname",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Position"){

        databaseQuery->prepare("select *from position where position = :position;");
        databaseQuery->bindValue(":position",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Hired"){

        databaseQuery->prepare("select *from staff where hired = :hired;");
        databaseQuery->bindValue(":hired",ui->lineEdit->text());
        databaseQuery->exec();
    }
    ////////////////////////////////////////////
    else if(ui->comboBox->currentText() == "Select"&&ui->comboTables->currentText() == "Clients"){

            databaseQuery->exec("select *from clients");
        }
        else if(ui->comboBox->currentText() == "ID"&&ui->comboTables->currentText() == "Clients"){

            databaseQuery->prepare("select *from clients where id = :id;");
            databaseQuery->bindValue(":id",ui->lineEdit->text());
            databaseQuery->exec();
        }
    else if(ui->comboBox->currentText() == "Full Name"){

        databaseQuery->prepare("select *from clients where name = :cname;");
        databaseQuery->bindValue(":cname",ui->lineEdit->text());
        databaseQuery->exec();
    }

    else if(ui->comboBox->currentText() == "Added"){

        databaseQuery->prepare("select *from clients where added = :added;");
        databaseQuery->bindValue(":added",ui->lineEdit->text());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Telephone number"){

        databaseQuery->prepare("select *from clients where telephone = :telephone;");
        databaseQuery->bindValue(":telephone",ui->lineEdit->text().toDouble());
        databaseQuery->exec();
    }


    else if(ui->comboBox->currentText() == "Address"){

        databaseQuery->prepare("select *from clients where address = :address;");
        databaseQuery->bindValue(":address",ui->lineEdit->text());
        databaseQuery->exec();
    }
    //////////////////////////////////////////
    else if(ui->comboBox->currentText() == "Select"&&ui->comboTables->currentText() == "Goods"){

            databaseQuery->exec("select *from goods");
        }
    else{
        databaseQuery->prepare("select *from goods where :value = :ivalue;");
        databaseQuery->bindValue(":value",ui->comboBox->currentText());
        databaseQuery->bindValue(":ivalue",ui->lineEdit->text());
        databaseQuery->exec();
    }



    databaseModel->setQuery(*databaseQuery);
    ui->tableView->setModel(databaseModel);
    ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    searchDB.closeConnection();
}

void AdminWindow::on_actionEdit_Entry_triggered()
{
    if(ui->comboTables->currentText()== "Animals")
       editDBentry.show();
    else if(ui->comboTables->currentText() == "Staff")
        EditStaff.show();
    else if(ui->comboTables->currentText() == "Clients")
        EditClient.show();
    else if(ui->comboTables->currentText() == "Goods")
        EditGoods.show();

}

void AdminWindow::on_actionRemove_Entry_triggered()
{
    if(ui->comboTables->currentText()== "Animals")
       removeEntry.show();
    else if(ui->comboTables->currentText() == "Staff")
        RemoveStaff.show();
    else if(ui->comboTables->currentText() == "Clients")
        RemoveClient.show();
    else if(ui->comboTables->currentText() == "Goods")
        RemoveGoods.show();

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


void AdminWindow::on_comboTables_highlighted(const QString &arg1)
{
    if(arg1 == "Staff"){
        ui->comboBox->clear();
        QStringList list1=(QStringList()<<"Select"<<"ID"<<"Name"<<"Surname"<<"Position"<<"Hired");
        ui->comboBox->addItems(list1);
    }
    if(arg1 == "Clients"){
        ui->comboBox->clear();
        QStringList list2=(QStringList()<<"Select"<<"ID"<<"Full Name"<<"Added"<<"Telephone number"<<"Address");
        ui->comboBox->addItems(list2);
    }
    if(arg1 == "Animals"){
        ui->comboBox->clear();
        QStringList list3=(QStringList()<<"Select"<<"ID"<<"Species"<<"Arrived"<<"Price");
        ui->comboBox->addItems(list3);
    }
    if(arg1== "Goods"){
        ui->comboBox->clear();
        QStringList list4=(QStringList()<<"Select"<<"id"<<"category"<<"name"<<"price"<<"amount"<<"status");
        ui->comboBox->addItems(list4);
    }
}

void AdminWindow::on_pushButton_2_clicked()
{
    AddClient.role=-1;
    AddClient.id=id;
    AddClient.show();
}

void AdminWindow::on_commandLinkButton_clicked()
{
    ui->comboTables->clear();
    QStringList list;
    if(role==1){
         list=(QStringList()<<"Staff"<<"Clients"<<"Animals"<<"Goods");
    }
    else if(role==0){
        list=(QStringList()<<"Clients"<<"Animals"<<"Goods");
    }
    else if(role==-1){
        list=(QStringList()<<"Animals"<<"Goods");
    }
    ui->comboTables->addItems(list);
    ui->comboTables->setEnabled(true);
}


void AdminWindow::on_checkBox_stateChanged(int arg1)
{
    if(arg1){
        ui->comboTables->clear();
        QStringList list;
        if(role==1){
             list=(QStringList()<<"Staff"<<"Clients"<<"Animals"<<"Goods");
             ui->actionEdit_Entry->setVisible(true);
             ui->actionRemove_Entry->setVisible(true);
             ui->actionNew_Entry->setVisible(true);
        }
        else if(role==0){
            list=(QStringList()<<"Clients"<<"Animals"<<"Goods");
            ui->actionEdit_Entry->setVisible(true);
            ui->actionRemove_Entry->setVisible(true);
            ui->actionNew_Entry->setVisible(true);
        }
        else if(role==-1){
            list=(QStringList()<<"Animals"<<"Goods");
        }
        ui->comboTables->addItems(list);

    }
    ui->comboTables->setEnabled(arg1);
    ui->label_2->setVisible(arg1);
}

void AdminWindow::on_tableView_clicked(const QModelIndex &index)
{
    connectDatabase searchDB;
    searchDB.openConnection();
    QSqlQuery query;
    int imgId=index.row()+1;

        // Get image data back from database
        query.prepare( "SELECT photo from animals where id = :id" );
        query.bindValue( ":id", imgId );
        if( !query.exec( ))
                qDebug() << "Error getting image from table:\n" << query.lastError();
        query.first();
        QByteArray outByteArray = query.value( 0 ).toByteArray();
        QPixmap outPixmap = QPixmap();
        outPixmap.loadFromData( outByteArray );


        int w = ui->label_3->width();
        int h = ui->label_3->height();

        // set a scaled pixmap to a w x h window keeping its aspect ratio
         ui->label_3->setPixmap(outPixmap.scaled(w,h,Qt::KeepAspectRatio));
        // Display image
        //QLabel myLabel;
        //ui->label_3->setScaledContents(outPixmap  );
//        myLabel.setScaledContents(outPixmap  );
//        myLabel.show();
         searchDB.closeConnection();

}

void AdminWindow::on_pushButton_3_clicked()
{
    connectDatabase searchDB;
    searchDB.openConnection();
    QSqlQuery query;
    QSqlQueryModel* databaseModel = new QSqlQueryModel;
    //int imgId=index.row()+1;

        // Get image data back from database
        query.prepare( "SELECT species from pets where owner = :id" );
        query.bindValue( ":id", id );
        if( !query.exec( ))
                qDebug() << "Error getting image from table:\n" << query.lastError();
        //query.first();
        QStringList species;
        while(query.next())
        {
            //if (query.isValid())
            species<<query.value(0).toString();
        }
        bool valid[6]={true};
        for(int i=0;i<species.length();i++){
            QSqlQuery query1;
            QString name=species.at(i);
            if(name=="cat"&&valid[0]){

                query1.prepare( "SELECT *from goods where category = :category" );
                query1.bindValue( ":category", "for cats" );
                if( !query1.exec( ))
                        qDebug() << "Error getting image from table:\n" << query.lastError();
                valid[0]=false;
            }
            else if(name=="dog"&&valid[1]){
                query1.prepare( "SELECT *from goods where category = :category" );
                query1.bindValue( ":category", "for dogs" );
                if( !query1.exec( ))
                        qDebug() << "Error getting image from table:\n" << query.lastError();
                valid[1]=false;
            }
            else if(name=="mouse"&&valid[2]){
                query1.prepare( "SELECT *from goods where category = :category" );
                query1.bindValue( ":category", "for mice" );
                if( !query1.exec( ))
                        qDebug() << "Error getting image from table:\n" << query.lastError();
                valid[2]=false;
            }
            else if(name=="panda"&&valid[3]){
                query1.prepare( "SELECT *from goods where category = :category" );
                query1.bindValue( ":category", "for pandas" );
                if( !query1.exec( ))
                        qDebug() << "Error getting image from table:\n" << query.lastError();
                valid[3]=false;
            }
            else if(name=="snake"&&valid[4]){
                query1.prepare( "SELECT *from goods where category = :category" );
                query1.bindValue( ":category", "for snakes" );
                if( !query1.exec( ))
                        qDebug() << "Error getting image from table:\n" << query.lastError();
                valid[4]=false;
            }
            while (query1.next()) {

                     databaseModel->insertRow(databaseModel->rowCount(),query1.value(0).toModelIndex());
             }
        }


        ui->tableView->setModel(databaseModel);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

         searchDB.closeConnection();
}
