#include "signup.h"
#include "adminwindow.h"
#include "databaseconnection.h"
#include "ui_signup.h"
using namespace std;
#define path "/home/anna/workspace/projects/progbase3/MyZooShop/users.sqlite"

SignUp::SignUp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SignUp)
{
    ui->setupUi(this);
//    MyDb=QSqlDatabase::addDatabase("QSQLITE");
//    MyDb.setDatabaseName(path);
//    QFileInfo checkFile(path);
//    if(checkFile.isFile()){
//        if(MyDb.open()){
//            ui->statusLabel->setText("[+] Connected");
//        }
//        else{
//             ui->statusLabel->setText("[!] connection error");
//        }
//    }
}

SignUp::~SignUp()
{
    delete ui;
    //MyDb.close();
}

void SignUp::on_loginButton_clicked()
{
    connectDatabase MyDb;
    MyDb.openConnection();

    if(!MyDb.openConnection())
    {
        QMessageBox::critical(this,"Database Error!","Error Connecting to Database! Please try again or Check Database.");
    }
    const QString password=hashFunc(ui->editPassword->text());
    const  QString name= ui->UsernameEdit->text();

    if(ui->lineEdit->text()!=ui->editPassword->text())
    {
        QMessageBox::warning(this,"Password error","Different password values!");
        on_clearButton_clicked();

    }
    else
    {
        //if()
        QSqlQuery query;
        query.prepare("INSERT INTO users (login,password_hash,role) VALUES(:login,:pass,:role);");
        query.bindValue(":login",name);
        query.bindValue(":pass", password);
        query.bindValue(":role", -1);
        bool written = query.exec();
        if (written)
        {
                QMessageBox::information(this,"Login was succesful","You are welcome");
                AdminWindow *aw = new AdminWindow();
                aw->role=-1;

                aw->Userid=// Get image data back from database
                        query1.prepare( "SELECT id from users where login = :login and password_hash = :pass and role =-1" );
                        query1.bindValue( ":id", imgId );
                        query1.bindValue(":login",name);
                        query1.bindValue(":pass", password);
                        if( !query1.exec( ))
                                qDebug() << "Error getting image from table:\n" << query1.lastError();
                        int userId=querry1.value(0).toInteger();



                aw->show();
                MyDb.closeConnection();
                this->close();
        }
        else
        {
            int res = QMessageBox::question(this, "Wrong login",
                                  "Login was NOT succesful. Try again?",
                                  QMessageBox::Yes | QMessageBox::No,
                                  QMessageBox::No);

            if(res == QMessageBox::Yes)
            {
               on_clearButton_clicked();
            }
            else
            {
                this->close();
            }
        }
    }

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

void SignUp::on_checkBox_clicked(bool checked)
{

}
