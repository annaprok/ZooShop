#include "client.h"
#include "common.h"
#include <cstdio>
#include <QTextCodec>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QDebug>
#include <QtGui>


Client::Client(QObject *parent) : QObject(parent)
{
    //QTcpSocket  client(this);


}
Client::~Client()
{
    //QTcpSocket  client(this);


}
QString  serializeRequest(Request request) {
    cout<<"Hello";
    QJsonDocument doc;
    QJsonObject root ;
    root.insert("functionName",request.functionName);
    root.insert("id",request.id);
    QJsonObject prof;
    Composer* p=&request.composer;
    prof.insert("name", p->name);
    prof.insert("amount of compositions", p->compositionsAmt);
     prof.insert("score", p->score);
     cout<<"Hello from serializeRequest\n";

     Composition *c=p->famousComposition;
     QJsonObject comp;
     comp.insert("name", c->getName());
     comp.insert("year", c->getYear());

    prof.insert("famous composition", comp);
    root.insert("composer",prof);
    root.insert("filename",request.fileName);

     doc.setObject(root);
     QString jsonStr=doc.toJson() ;
    return jsonStr;
}

 int Client::sendRequest(ZooRequest & req, ZooResponse & res,QString&path )
 {
//        QTcpSocket* client=new QTcpSocket(this);
//        int PORT=3000;
//        QHostAddress serverAddress("127.0.0.1");
//         client->connectToHost((QHostAddress)"127.0.0.1",3000);
//         cout<<"{Client} connecting to socket from port "<<PORT<<" from address "<<serverAddress.toString().toStdString()<<endl;
//         client->waitForConnected(2000);
//         if(client->state()!=QAbstractSocket::ConnectedState){
//             cerr<<"{Client} connection error"<<endl;
//             return 1;
//         }
//         cout<<"{Client} connecting to server"<<endl;

//         QString requestStr=serializeZooRequest(req);
//         cout<<"{Client}"<<endl;
//         // @todo check out
//         cout<<"{Client} Sending:"<<endl<<requestStr.toStdString()<<endl;
//         client->write(requestStr.toUtf8());
//         client->flush();
//         client->waitForBytesWritten(2000);
//         cout<<"{Client} request sent"<<endl;
//         //
//         if(!client->waitForReadyRead(2000)){
//             cerr<<"{Client} read error"<<endl;
//         }
//         //



//         QByteArray data=client->readAll();
//         cout<<"{Client} Recieved:"<<endl<<data.toStdString()<<endl;
//         //
//         //QString str=QTextCodec::codecForMib(1015)->toUnicode(data);
//         res=*lib.deserializeZooResponse(data);

//         client->disconnectFromHost();
//         cout<<"{Client} disconnected"<<endl;
//         delete client;

//    return 0;
}


