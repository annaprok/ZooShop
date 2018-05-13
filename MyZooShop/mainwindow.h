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
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
