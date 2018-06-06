#include "login.h"
#include "adminwindow.h"
#include "ui_login.h"
#include <iostream>
#include <QString>
using namespace std;
#define path "/home/anna/workspace/projects/progbase3/MyZooShop/users.sqlite"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    accepted=false;
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

LogIn::~LogIn()
{
    delete ui;


    MyDb.close();
    cout<<"close db"<<endl;
}

void LogIn::setUsername(QString &username){
//     bool found = false;
//     for( int i = 0; i <  ui->comboUsername->count() && ! found ; i++ )
//         if(  ui->comboUsername->itemText( i ) == username ){
//              ui->comboUsername->setCurrentIndex( i );
//             found = true;
//         }

//        if( ! found ){
//             int index =  ui->comboUsername->count();
//             qDebug() << "Select username " << index;
//              ui->comboUsername->addItem( username );

//              ui->comboUsername->setCurrentIndex( index );
//         }

//    // place the focus on the password field
//     ui->editPassword->setFocus();
//}

//void LogIn::setPassword(QString &password){
//     ui->editPassword->setText( password );
}

//void LogIn::slotAcceptLogin(){
//     QString username =  ui->comboUsername->currentText();
//     QString password =  ui->editPassword->text();
//     int index =  ui->comboUsername->currentIndex();

//    emit acceptLogin( username, // current username
//     password, // current password
//     index // index in the username list
//     );

//    // close this dialog
//     this->close();
//}

//void LogIn::setUsernamesList(const QStringList &usernames){
// ui->comboUsername->addItems( usernames );
//}

//void AddDialog::validform(){
//    bool valid = !ui->fComp_edit->text().isEmpty() && !ui->name_edit->text().isEmpty();
//    ui->okBtn->setEnabled(valid);
//}

//void AddDialog::onButtonSend()
//{
//   emit sendData(ui->name_edit->text(),ui->amt_edit->value(),ui->score_edit->value(),
//                 ui->fComp_edit->text(),ui->year_edit->value()); // вызываем сигнал, в котором передаём введённые данные
//   this->close();
//}

//void AddDialog::on_pushButton_clicked()
//{
//    this->close();
//}
//void LogIn::on_login_edit_textChanged(const QString &arg1)
//{
    
//}


//void LogIn::on_password_edit_textChanged(const QString &arg1)
//{
    
//}

void LogIn::on_clearButton_clicked()
{
    ui->UsernameEdit->setText("");
    ui->editPassword->setText("");
}

void LogIn::on_loginButton_clicked()
{
    QString password=hashFunc(ui->editPassword->text());

    if (!MyDb.open())
      {
         qDebug() << "Error: connection with database fail";
      }
      else
      {
         qDebug() << "Database: connection ok";
      }
    QSqlQuery query;
    query.prepare("SELECT login,password_hash,role FROM users WHERE login = (:name) AND password_hash = (:pass)");
    query.bindValue(":name", ui->UsernameEdit->text());
    query.bindValue(":pass", password);

    if (query.exec())
    {
       if (query.next())
       {
          ui->statusLabel->setText("[+] Valid login");
          int status = query.record().value("role").toInt();
          accepted=true;
          role=status;
          emit acceptLogin(ui->UsernameEdit->text(),password,status );
          if(status==1){
            QMessageBox::information(this,"Login was succesful","Welcome administrator!");
            AdminWindow *aw=new AdminWindow();
            aw->show();

          }
          else if(status==0){
              QMessageBox::information(this,"Login was succesful","Welcome seller!");
          }

          this->close();
       }
       else{
           ui->statusLabel->setText("[-] Wrong login");
           int res = QMessageBox::question(this, "Wrong login",
                                 "Login was NOT succesful. Try again?",
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::No);

           if(res == QMessageBox::Yes){
              on_clearButton_clicked();
           } else {
               emit rejectLog();
               this->close();
           }
       }
      }
       else{
           ui->statusLabel->setText("[-] Wrong login");
           int res = QMessageBox::question(this, "Wrong login",
                                 "Login was NOT succesful. Try again?",
                                 QMessageBox::Yes | QMessageBox::No,
                                 QMessageBox::No);

           if(res == QMessageBox::Yes){
              on_clearButton_clicked();
           } else {
               this->close();
           }
       }

}

QString LogIn::hashFunc(QString password){
     QString str= QString::fromStdString(md5(password.toStdString()));
     return str;
}
