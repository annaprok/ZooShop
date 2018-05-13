#include "mainwindow.h"
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
#include <QTextCodec>                   //     создания кодеков для отображения  текста

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
