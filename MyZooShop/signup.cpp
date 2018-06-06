#include "signup.h"
#include "ui_signup.h"
using namespace std;
#define path "/home/anna/workspace/projects/progbase3/MyZooShop/users.sqlite"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
    MyDb=QSqlDatabase::addDatabase("QSQLITE");
    MyDb.setDatabaseName(path);
    QFileInfo checkFile(path);
    if(checkFile.isFile()){
        if(MyDb.open()){
            ui->statusLabel->setText("[+] Connected");
        }
        else{
             ui->statusLabel->setText("[!] connection error");
        }
    }
}

SignUp::~SignUp()
{
    delete ui;
    MyDb.close();
}

void SignUp::on_loginButton_clicked()
{
    const QString password=hashFunc(ui->editPassword->text());
   const  QString name= ui->UsernameEdit->text();

    if (!MyDb.open())
      {
         qDebug() << "Error: connection with database fail";
      }
      else
      {
         qDebug() << "Database: connection ok";
      }
    if(ui->lineEdit->text()!=ui->editPassword->text()){
        QMessageBox::warning(this,"Password error","Different password values!");
        on_clearButton_clicked();

    }
    else{
        QSqlQuery query;
        query.prepare("INSERT INTO users (login,password_hash) VALUES(:login,:pass);");
        query.bindValue(":login",name);
        query.bindValue(":pass", password);
 bool written = query.exec();
    if (written)
    {
            QMessageBox::information(this,"Login was succesful","You are welcome");

       }
      }
      this->close();
}

void SignUp::on_clearButton_clicked()
{
    ui->UsernameEdit->setText("");
    ui->editPassword->setText("");
}
QString SignUp::hashFunc(QString password){
     QString str= QString::fromStdString(md5(password.toStdString()));
     return str;
}
