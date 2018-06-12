#include "storage.h"

Storage::Storage(int PORT, QHostAddress serverAddress)
{
   this->PORT=PORT;
    this->serverAddress=serverAddress;
    c=new Client();
}
Storage::Storage()
{
   this->PORT=3000;
    this->serverAddress=QHostAddress("127.0.0.1");
    c=new Client();
}
//QStringList Storage::getAllFilesNew() {
//    Request req;
//    req.functionName = FunctionName::FN_GET_FILES;
//    Response res;

//    cerr<<"addr //storage "<<serverAddress.toString().toStdString()<<endl;

//    int status = c->sendRequest(req, res, PORT, serverAddress); // @todo where
//    if (status != 0) {
//        cerr<<"Send request error //storage\n";
//        return QStringList(0);
//    }

//    return res.files;
//}

////void Storage::clearList() {
////    Request req = {0};
////    req.functionName = FN_NEW_LIST;
////    Response res = {0};
////    int status = Client_sendRequest(&req, &res);
////    if (status != 0) {
////        fprintf(stderr, "Send request error\n");
////    }
////}

//int Storage::loadListFromFile(QString fileName,QList<Composer*> * list) {
//    Request req;
//    req.functionName = FunctionName::FN_LOAD_LIST;
//    req.fileName= fileName;
//    Response res;
//    int status = c->sendRequest(req, res, PORT, serverAddress); // @todo where
//    if (status != 0) {
//        cerr<<"Send request error //storage\n";
//        return 1;
//    }
//    list=&res.composers;
//    return res.status;
//}

////int Storage::saveListToFile(Storage * self, const char * fileName) {
////    Request req = {0};
////    req.functionName = FN_SAVE_LIST;
////    strcpy(req.fileName, fileName);
////    Response res = {0};
////    int status = Client_sendRequest(&req, &res);
////    if (status != 0) {
////        fprintf(stderr, "Send request error\n");
////        return 1;
////    }
////    Response_clear(&res);
////    return res.status;
////}

////// CRUD operations

//QList<Composer*> *  Storage::getAllStudentsNew() {
//    Request req;
//    req.functionName = FunctionName::FN_GET_STUDENTS;
//    Response res;
//    int status = c->sendRequest(req, res, PORT, serverAddress); // @todo where
//    if (status != 0) {
//        cerr<<"Send request error //storage\n";
//        return nullptr;
//    }
//    return &res.composers;
//}

//int Storage::insertStudent(Composer * composer) {
//    Request req;
//    req.functionName = FunctionName::FN_INSERT_STUDENT;
//    req.composer = *composer;
//    Response res;
//    int status =c->sendRequest(req, res, PORT, serverAddress);
//    if (status != 0) {
//        cerr<<"Send request error //storage\n";
//        return -1;
//    }
//    return res.id;
//}

////int Storage::updateStudent(Storage * self, Student * student) {
////    Request req = {0};
////    req.functionName = FN_UPDATE_STUDENT;
////    req.student = *student;
////    Response res = {0};
////    int status = Client_sendRequest(&req, &res);
////    if (status != 0) {
////        fprintf(stderr, "Send request error\n");
////        return -1;
////    }
////    return res.status;
////}

//int Storage::deleteStudent(int id) {
//    Request req;
//    req.functionName = FunctionName::FN_DELETE_STUDENT;
//    req.id = id;
//    Response res;
//    int status =c->sendRequest(req, res, PORT, serverAddress);
//    if (status != 0) {
//        cerr<<"Send request error //storage\n";
//        return -1;
//    }
//    return res.status;
//}

//int Storage::deleteFile(QString file) {
//    Request req;
//    req.functionName = FunctionName::FN_NONE;
//    req.fileName=file;
//    Response res;
//    int status =c->sendRequest(req, res, PORT, serverAddress);
//    if (status != 0) {
//        cerr<<"Send request error //storage\n";
//        return -1;
//    }
//    return res.status;
//}

bool Storage::addAnimal(Animal*animal ) {
    ZooRequest req;
    req.functionName = ZooFuncName::FN_ADD_ANIMAL;
    req.animal = *animal;
    ZooResponse res;
    QHostAddress serverAddress("127.0.0.1");
    int status =c->sendZooRequest(req, res, PORT,serverAddress);
    if (status != 0) {
        cerr<<"Send request error //storage\n";
        return false;
    }
    return true;
}

bool Storage::deleteAnimal(int id ) {
    ZooRequest req;
    req.functionName = ZooFuncName::FN_DELETE_ANIMAL;
    req.id = id;
    ZooResponse res;
    QHostAddress serverAddress("127.0.0.1");
    int status =c->sendZooRequest(req, res, PORT,serverAddress);
    if (status != 0) {
        cerr<<"Send request error //storage\n";
        return false;
    }
    return true;
}




