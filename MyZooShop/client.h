#ifndef CLIENT_H
#define CLIENT_H
#include "common.h"
#include <QCoreApplication>
#include <QTcpServer>
#include <QTcpSocket>
#include <QObject>
#include <iostream>
using namespace std;

class Client: public QObject
{
    //Q_OBJECT
    public:
    Common lib;
    explicit Client(QObject *parent = nullptr);
    virtual ~Client();

    int sendRequest(ZooRequest & req, ZooResponse & res,QString&path );
};

#endif // CLIENT_H
