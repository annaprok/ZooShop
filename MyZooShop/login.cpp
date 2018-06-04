#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    connect( buttons->button( QDialogButtonBox::Cancel ),
     SIGNAL (clicked()),
     this,
     SLOT (close())
     );

    connect( buttons->button( QDialogButtonBox::Ok ),
     SIGNAL (clicked()),
     this,
     SLOT (slotAcceptLogin()) );
}

LogIn::~LogIn()
{
    delete ui;
}

void LogIn::setUsername(QString &username){
     bool found = false;
     for( int i = 0; i <  ui->comboUsername->count() && ! found ; i++ )
         if(  ui->comboUsername->itemText( i ) == username ){
              ui->comboUsername->setCurrentIndex( i );
             found = true;
         }

        if( ! found ){
             int index =  ui->comboUsername->count();
             qDebug() << "Select username " << index;
              ui->comboUsername->addItem( username );

              ui->comboUsername->setCurrentIndex( index );
         }

    // place the focus on the password field
     ui->editPassword->setFocus();
}

void LogIn::setPassword(QString &password){
     ui->editPassword->setText( password );
}

void LogIn::slotAcceptLogin(){
     QString username =  ui->comboUsername->currentText();
     QString password =  ui->editPassword->text();
     int index =  ui->comboUsername->currentIndex();

    emit acceptLogin( username, // current username
     password, // current password
     index // index in the username list
     );

    // close this dialog
     this->close();
}

void LogIn::setUsernamesList(const QStringList &usernames){
 ui->comboUsername->addItems( usernames );
}

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
