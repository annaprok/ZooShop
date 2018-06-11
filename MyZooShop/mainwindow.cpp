#include "mainwindow.h"
#include "login.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>          // создания или подключение базы
#include <QtSql/QSqlError>               // ошибок подключения
#include <QtSql/QSqlQuery>               // ошибок запросов
#include <QMessageBox>                   //  текстовых сообщений
#include <QtSql/QSqlTableModel>      //создания реляционной таблицы
#include <QDataWidgetMapper>        // создания определённых виджетов
#include <QFile>                     //              создания для работы с файлами
#include <QSqlRelationalDelegate>     //создания реляционного делегата типа sql
#include <QDate>                      //            создания функции для работы с датами в Qt4
#include <QApplication>               //        создания аппликации                //             создания класса Qprinter
#include <QTextDocument>              //    создания класса QTextDocument
#include <QTextCodec>
#include <iostream> //     создания кодеков для отображения  текста
#define path "/home/anna/workspace/projects/progbase3/MyZooShop/users.sqlite"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    client= new QTcpSocket(this);
    aw=new AdminWindow();
    login= new LogIn();
    signup=new SignUp();
//    connect( login,
//     SIGNAL (acceptLogin(QString,QString,int)),
//     this,
//     SLOT (slotAcceptUserLogin(QString,QString,int)));
//    connect( login,
//     SIGNAL (rejectLog()),
//     this,
//     SLOT(close()));
//    login->exec();
//    aw->show();

}

MainWindow::~MainWindow()
{
    delete ui;
}
//void MainWindow::slotAcceptUserLogin(QString name,QString passw,int role)
//{
//    if(role==1){
//        cout<<"admin"<<endl;

//    }
//    else if(role==0){
//          cout<<"seller"<<endl;
//    }

//}

void MainWindow::on_showAniButton_clicked()
{

    QSqlDatabase MyDb=QSqlDatabase::addDatabase("QSQLITE");
    MyDb.setDatabaseName(path);
    if(!MyDb.open()){
        MyDb.close();
    }
    QSqlTableModel *model = new QSqlTableModel(this,MyDb);
      model->setTable("animals");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();
      model->setHeaderData(0, Qt::Horizontal, tr("№"));


//      ui->tableView->setModel(model);
//      ui->tableView->show();
       MyDb.close();
}



void MainWindow::on_showGoodsButton_clicked()
{
    QSqlDatabase MyDb=QSqlDatabase::addDatabase("QSQLITE");
    MyDb.setDatabaseName(path);
    if(!MyDb.open()){
        MyDb.close();
    }
    QSqlTableModel *model = new QSqlTableModel(this,MyDb);
      model->setTable("goods");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();
      model->setHeaderData(0, Qt::Horizontal, tr("№"));


//      ui->tableView->setModel(model);
//      ui->tableView->show();
       MyDb.close();

}

void MainWindow::on_showCustomersButton_clicked()
{
    QSqlDatabase MyDb=QSqlDatabase::addDatabase("QSQLITE");
    MyDb.setDatabaseName(path);
    if(!MyDb.open()){
        MyDb.close();
    }
    QSqlTableModel *model = new QSqlTableModel(this,MyDb);
      model->setTable("clients");
      model->setEditStrategy(QSqlTableModel::OnManualSubmit);
      model->select();
      model->setHeaderData(0, Qt::Horizontal, tr("№"));


//      ui->tableView->setModel(model);
//      ui->tableView->show();
       MyDb.close();
}

void MainWindow::on_selectButton_clicked()
{


}

void MainWindow::on_register_btn_clicked()
{
    signup->show();
    this->close();
}

void MainWindow::on_login_btn_clicked()
{
    login->show();
    this->close();
}
