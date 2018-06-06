#ifndef STORAGE_H
#define STORAGE_H
#include <QApplication>
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <iostream>
#include <QObject>
#include<QList>
#include <QStringList>
#include"common.h"
#include"client.h"
#include <QTcpSocket>
#include <QHostAddress>


class Storage
{
public:
    Storage(int PORT, QHostAddress serverAddress);
    Storage();
     Client* c;
    int PORT=3000;
    QTcpSocket*client;
    QHostAddress serverAddress;
    QStringList  getAllFilesNew();
    void clearList();
    int loadListFromFile(QString fileName,QList<Composer*> * list);
    int saveListToFile(QString fileName,QList<Composer*> * list);

    // CRUD operations
    QList<Composer *> *getAllStudentsNew();
    int insertStudent(Composer *composer);
    int updateStudent(Composer * composer);
    int deleteStudent(int id);
    int deleteFile(QString file);
};

#endif // STORAGE_H
