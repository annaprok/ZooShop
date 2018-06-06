#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>      //кодеки для использования русских симовлов
#include <QtSql/QSqlDatabase> // создание или подключение базы
#include <QtSql/QSqlRelationalTableModel> //оздание реляционной таблицы модели
#include <QApplication>   //создание аппликации
#include <QDataWidgetMapper>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <QDebug>
#include <iostream>
#include "storage.h"
#include "adminwindow.h"
#include "login.h"
#include "signup.h"
#include <QMainWindow>
#include <QList>
#include <QListWidgetItem>
#include <QMessageBox>
using namespace std;
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //create storage
//    QString path="path";
//    Storage*_storage=new Storage(path);
//    if(!_storage->open()){
//        QMessage
//    }
//    QList<User*> users=_storage->getAllUsers();
public:
    int PORT=3000;
    QTcpSocket*client;
    QHostAddress serverAddress;
    Storage *storage;
    int status;
    AdminWindow *aw;


    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //bool login(const QString &userName, const QString &password);
    void logout();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_database;
     LogIn *login;
     SignUp*signup;
public slots:
    //void slotAcceptUserLogin(QString name,QString passw,int role);
private slots:
    void on_showAniButton_clicked();

    void on_showGoodsButton_clicked();
    void on_showCustomersButton_clicked();
    void on_selectButton_clicked();
    void on_register_btn_clicked();
    void on_login_btn_clicked();
};

#endif // MAINWINDOW_H
