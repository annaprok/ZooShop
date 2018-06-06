#include "dbmanager.h"

DbManager::DbManager(QString &path)
{
  PATH=path;
   c=new Client();
}

QSqlTableModel DbManager::showAnimals(QString & Path)
{

//    QSqlTableModel *model;
//    ZooRequest req;
//    req.functionName = FunctionName::FN_SHOW_ANIMALS;
//    req.path=Path;
//    Response res;
//    model =c->sendRequest(req, res,PATH);
//    if (model == nullptr) {
//        cerr<<"Send request error //storage\n";
//        return nullptr;
//    }
//    return model;

}

