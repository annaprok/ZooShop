#ifndef COMMON_H
#define COMMON_H
#ifndef REQUEST_H
#define REQUEST_H

#include "common_global.h"
#include <iostream>
#include <QString>
#include "composer.h"
#include "composition.h"
#include <QStringList>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QtSql/QSqlDatabase>          // создания или подключение базы
#include <QtSql/QSqlError>               // ошибок подключения
#include <QtSql/QSqlTableModel>
using namespace std;


class COMMONSHARED_EXPORT Composition
{
//    QString name;
//    int year;
public:
    QString name;
    int year;
    Composition(QString name, int year);
    Composition();
    QString getName();
    int getYear();
    void setName(QString name);
    void setYear(int year);
};

class COMMONSHARED_EXPORT Composer
{

public:
    int id;
    QString  name ;
    int compositionsAmt;
    double score;
    Composition* famousComposition;

    Composer(int id, QString & name, int amt, double score, QString cname, int year);

    Composer();
    Composer(Composer*comp);
    Composer(int id, QString & name, int amt, double score,Composition*comp);
    QString getName();
    int getAmount();
    double getScore();
    Composition* getComposition();
    QString getCompName();
    int getYear();
    void setName(QString & name);

    void setAmount(int amt);
    void setScore(double score);
    void setComposition(QString cname,int year);



};

class COMMONSHARED_EXPORT FunctionName
{
public:
    typedef enum {
        FN_NONE,
        FN_GET_FILES,
        FN_NEW_LIST,
        FN_LOAD_LIST,
        FN_SAVE_LIST,
        FN_GET_STUDENTS,
        FN_INSERT_STUDENT,
        FN_UPDATE_STUDENT,
        FN_DELETE_STUDENT,
        FN_SHOW_ANIMALS
    } FuncName;
    QString toString(FuncName fn);
    FunctionName();
};





class COMMONSHARED_EXPORT Request
{
 public:
    FunctionName::FuncName functionName;
    int id;
    Composer composer;
    QString fileName;
    void clear(Request & req);
    Request();
};




class COMMONSHARED_EXPORT Response
{
 public:
    int status;
    int id;
    QStringList  files;
    QList<Composer*> composers;
    Response();
};







////////////////////////////////////////////////////////////////////
/// \brief The ZooRequest class
class COMMONSHARED_EXPORT ZooFuncName
{
public:
    typedef enum {
        FN_NONE,
        FN_SHOW_ANIMALS
    } FuncName;
    QString toString(FuncName fn);
    ZooFuncName();
};


class COMMONSHARED_EXPORT ZooRequest
{
 public:
    FunctionName::FuncName functionName;
    int id;
    QString path;
    //Composer composer;
    //QString fileName;
    void clear(ZooRequest & req);
    //ZooRequest();
};
class COMMONSHARED_EXPORT ZooResponse
{
 public:
    int status;
    int id;
    QSqlTableModel model;
    //QStringList  files;
    //QList<Composer*> composers;
    ZooResponse();
};



/////////////////////////////////////////////////
class COMMONSHARED_EXPORT Common
{


public:
    Common();
    QList<Composer*> * deserializeComposersToList(QString val);
    QString serializeComposersFromList(QList<Composer*> * list);
    Response * deserializeResponse(QString  text);
    QString serializeRequest(Request request);
    Request * deserializeRequest(QString text);
    QString serializeResponse(Response * response);
    ///////////////////////////////////////////////////////////////
    ZooResponse * deserializeZooResponse(QString  text);
    QString serializeZooRequest(ZooRequest request);
    ZooRequest * deserializeZooRequest(QString text);
    QString serializeZooResponse(ZooResponse * response);
    QString serializeModel(QSqlTableModel *m_model);
    QSqlTableModel * deserializeModel(QString &str);
};

#endif // COMMON_H
#endif // COMMON_H
