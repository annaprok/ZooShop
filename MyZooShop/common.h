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
        FN_DELETE_STUDENT
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
};


#endif // COMMON_H
#endif // COMMON_H
