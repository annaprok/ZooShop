#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextCodec>      //кодеки для использования русских симовлов
#include <QtSql/QSqlDatabase> // создание или подключение базы
#include <QtSql/QSqlRelationalTableModel> //оздание реляционной таблицы модели
#include <QApplication>   //создание аппликации
#include <QDataWidgetMapper>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    //create storage
    QString path="path";
    Storage*_storage=new Storage(path);
    if(!_storage->open()){
        QMessage
    }
    QList<User*> users=_storage->getAllUsers();


    Q_OBJECT



public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    bool login(const QString &userName, const QString &password);
    void logout();

private:
    Ui::MainWindow *ui;
    QSqlDatabase m_database;
};

#endif // MAINWINDOW_H
