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
  client=new QTcpSocket(this);

}
Client::~Client()
{
    delete client;
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

 /*int Client::sendRequest(Request & req, Response & res,int PORT, QHostAddress & serverAddress )
 {
        QTcpSocket* client=new QTcpSocket(this);
         client->connectToHost(serverAddress, PORT);
         cout<<"{Client} connecting to socket from port "<<PORT<<" from address "<<serverAddress.toString().toStdString()<<endl;
         client->waitForConnected(2000);
         if(client->state()!=QAbstractSocket::ConnectedState){
             cerr<<"{Client} connection error"<<endl;
             return 1;
         }
         cout<<"{Client} connecting to server"<<endl;
         //


//         QJsonDocument doc;
//         QJsonObject root ;
//         root.insert("functionName",(&req)->functionName);
//         root.insert("id",(&req)->id);
//         QJsonObject prof;
//         Composer* p=&(&req)->composer;
//         prof.insert("name", p->name);
//         prof.insert("amount of compositions", p->compositionsAmt);
//          prof.insert("score", p->score);
//          cout<<"Hello from serializeRequest\n";

//          Composition *c=p->famousComposition;
//          QJsonObject comp;
//          comp.insert("name", c->getName());
//          comp.insert("year", c->getYear());

//         prof.insert("famous composition", comp);
//         root.insert("composer",prof);
//         root.insert("filename",(&req)->fileName);

//          doc.setObject(root);
//          QString jsonStr=doc.toJson() ;
         QString requestStr=serializeRequest(req);
         cout<<"{Client}"<<endl;
         // @todo check out
         cout<<"{Client} Sending:"<<endl<<requestStr.toStdString()<<endl;
         client->write(requestStr.toUtf8());
         client->flush();
         client->waitForBytesWritten(2000);
         cout<<"{Client} request sent"<<endl;
         //
         if(!client->waitForReadyRead(2000)){
             cerr<<"{Client} read error"<<endl;
         }
         //



         QByteArray data=client->readAll();
         cout<<"{Client} Recieved:"<<endl<<data.toStdString()<<endl;
         //
         //QString str=QTextCodec::codecForMib(1015)->toUnicode(data);
         res=*lib.deserializeResponse(data);

         client->disconnectFromHost();
         cout<<"{Client} disconnected"<<endl;
         delete client;
//    TcpClient client;
//    TcpClient_init(&client);
//    if (!TcpClient_connect(&client, IpAddress_init(&(IpAddress){}, "127.0.0.1", 3030))) {
//        fprintf(stderr, "[Client]> Can't connect to server\n");
//        return 1;
//    }
//    printf("[Client]> Connected to server\n");
//    fflush(stdout);

//    char buffer[2048] = "";
//    NetMessage message;
//    NetMessage_init(&message, buffer, 2048);

//    const char * out = Serialization_serializeRequest(req);
//    // @todo check out
//    NetMessage_setDataString(&message, out);
//    free((void *)out);

//    if (!TcpClient_send(&client, &message)) {
//        fprintf(stderr, "[Client]> Can't send request\n");
//        return 1;
//    }

//    printf("[Client]> Request sent.\n");

//    if (!TcpClient_receive(&client, &message)) {
//        fprintf(stderr, "[Client]> Can't receive response\n");
//        return 1;
//    }
//    const char * in = NetMessage_data(&message);
//    printf("[Client]> Got response\n%s\n", in);

//    *res = Serialization_deserializeResponse(in);
//    TcpClient_close(&client);
    return 0;
}*/
int Client::sendRequest(Request & req, Response & res,int PORT, QHostAddress & serverAddress )
 {
        QTcpSocket* client=new QTcpSocket(this);
         client->connectToHost(serverAddress, PORT);
         cout<<"{Client} connecting to socket from port "<<PORT<<" from address "<<serverAddress.toString().toStdString()<<endl;
         client->waitForConnected(2000);
         if(client->state()!=QAbstractSocket::ConnectedState){
             cerr<<"{Client} connection error"<<endl;
             return 1;
         }
         cout<<"{Client} connecting to server"<<endl;
         //


//         QJsonDocument doc;
//         QJsonObject root ;
//         root.insert("functionName",(&req)->functionName);
//         root.insert("id",(&req)->id);
//         QJsonObject prof;
//         Composer* p=&(&req)->composer;
//         prof.insert("name", p->name);
//         prof.insert("amount of compositions", p->compositionsAmt);
//          prof.insert("score", p->score);
//          cout<<"Hello from serializeRequest\n";

//          Composition *c=p->famousComposition;
//          QJsonObject comp;
//          comp.insert("name", c->getName());
//          comp.insert("year", c->getYear());

//         prof.insert("famous composition", comp);
//         root.insert("composer",prof);
//         root.insert("filename",(&req)->fileName);

//          doc.setObject(root);
//          QString jsonStr=doc.toJson() ;
         QString requestStr=serializeRequest(req);
         cout<<"{Client}"<<endl;
         // @todo check out
         cout<<"{Client} Sending:"<<endl<<requestStr.toStdString()<<endl;
         client->write(requestStr.toUtf8());
         client->flush();
         client->waitForBytesWritten(2000);
         cout<<"{Client} request sent"<<endl;
         //
         if(!client->waitForReadyRead(2000)){
             cerr<<"{Client} read error"<<endl;
         }
         //



         QByteArray data=client->readAll();
         cout<<"{Client} Recieved:"<<endl<<data.toStdString()<<endl;
         //
         //QString str=QTextCodec::codecForMib(1015)->toUnicode(data);
         res=*lib.deserializeResponse(data);

         client->disconnectFromHost();
         cout<<"{Client} disconnected"<<endl;
         delete client;
//    TcpClient client;
//    TcpClient_init(&client);
//    if (!TcpClient_connect(&client, IpAddress_init(&(IpAddress){}, "127.0.0.1", 3030))) {
//        fprintf(stderr, "[Client]> Can't connect to server\n");
//        return 1;
//    }
//    printf("[Client]> Connected to server\n");
//    fflush(stdout);

//    char buffer[2048] = "";
//    NetMessage message;
//    NetMessage_init(&message, buffer, 2048);

//    const char * out = Serialization_serializeRequest(req);
//    // @todo check out
//    NetMessage_setDataString(&message, out);
//    free((void *)out);

//    if (!TcpClient_send(&client, &message)) {
//        fprintf(stderr, "[Client]> Can't send request\n");
//        return 1;
//    }

//    printf("[Client]> Request sent.\n");

//    if (!TcpClient_receive(&client, &message)) {
//        fprintf(stderr, "[Client]> Can't receive response\n");
//        return 1;
//    }
//    const char * in = NetMessage_data(&message);
//    printf("[Client]> Got response\n%s\n", in);

//    *res = Serialization_deserializeResponse(in);
//    TcpClient_close(&client);
    return 0;
}

int Client::sendZooRequest(ZooRequest & req, ZooResponse & res,int PORT, QHostAddress & serverAddress  )
 {
       // QTcpSocket* client=new QTcpSocket(this);
//        int PORT=3000;
        //QHostAddress serverAddress("127.0.0.1");
         client->connectToHost(serverAddress,3000);
         cout<<"{Client} connecting to socket from port "<<PORT<<" from address "<<serverAddress.toString().toStdString()<<endl;
         client->waitForConnected(2000);
         if(client->state()!=QAbstractSocket::ConnectedState){
             cerr<<"{Client} connection error"<<endl;
             return 1;
         }
         cout<<"{Client} connecting to server"<<endl;

         QString requestStr=lib.serializeZooRequest(req);
         cout<<"{Client}"<<endl;
         // @todo check out
         cout<<"{Client} Sending:"<<endl<<requestStr.toStdString()<<endl;
         client->write(requestStr.toUtf8());
         client->flush();
         client->waitForBytesWritten(2000);
         cout<<"{Client} request sent"<<endl;
         //
         if(!client->waitForReadyRead(2000)){
             cerr<<"{Client} read error"<<endl;
         }
         //



         QByteArray data=client->readAll();
         cout<<"{Client} Recieved:"<<endl<<data.toStdString()<<endl;
         //
         //QString str=QTextCodec::codecForMib(1015)->toUnicode(data);
         res=*lib.deserializeZooResponse(data);

         client->disconnectFromHost();
         cout<<"{Client} disconnected"<<endl;
         delete client;

    return 0;
}
