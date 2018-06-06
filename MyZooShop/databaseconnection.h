#ifndef DATABASECONNECTION_H
#define DATABASECONNECTION_H

#include <QMainWindow>
#include <QtSql>
#include <QDebug>
#include <QFileInfo>
#include <QDebug>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSql>
#include <QSqlQueryModel>
#include <string>
#include <QString>
#include <QDir>
#include <QComboBox>

class connectDatabase
{
public:
    connectDatabase() {}
    QSqlDatabase DB = QSqlDatabase::addDatabase("QSQLITE");
    bool openConnection(){
        QString databasePath = "/home/anna/workspace/projects/progbase3/MyZooShop/users.sqlite";
        DB.setDatabaseName(databasePath);
        return DB.open();
    }

    void closeConnection(){
        DB.close();
     }
  };

#endif // DATABASECONNECTION_H
