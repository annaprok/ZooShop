#include "login.h"
#include "ui_login.h"

LogIn::LogIn(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LogIn)
{
    ui->setupUi(this);
    //ui->login_edit->setValidator(new QRegExpValidator(QRegExp("[A-Za-z `]+")));
    connect(ui->okBtn, SIGNAL(clicked()), this, SLOT(onButtonSend()));
    connect(this, SIGNAL(sendData(QString, int, double, QString, int)),
            QWidget::parentWidget (), SLOT(recieveData(QString, int, double, QString, int)));
}

LogIn::~LogIn()
{
    delete ui;
}

void AddDialog::validform(){
    bool valid = !ui->fComp_edit->text().isEmpty() && !ui->name_edit->text().isEmpty();
    ui->okBtn->setEnabled(valid);
}

void AddDialog::onButtonSend()
{
   emit sendData(ui->name_edit->text(),ui->amt_edit->value(),ui->score_edit->value(),
                 ui->fComp_edit->text(),ui->year_edit->value()); // вызываем сигнал, в котором передаём введённые данные
   this->close();
}

void AddDialog::on_pushButton_clicked()
{
    this->close();
}
void LogIn::on_login_edit_textChanged(const QString &arg1)
{
    
}


void LogIn::on_password_edit_textChanged(const QString &arg1)
{
    
}
