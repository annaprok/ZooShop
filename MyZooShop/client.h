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
    Q_OBJECT
    public:
    Common lib;
    QTcpSocket* client;
    explicit Client(QObject *parent = nullptr);
    virtual ~Client();

    int sendZooRequest(ZooRequest & req, ZooResponse & res,int PORT, QHostAddress & serverAddress );
    int sendRequest(Request & req, Response & res,int PORT, QHostAddress & serverAddress);
};

#endif // CLIENT_H
