#include "databaseconnection.h"
void connectDatabase::selectAllAnimals(){
    //databaseQuery->exec("select *from animals");
}

void selectAnimals(int field,QString data){
//    switch(field){
//         case 1:{
//        databaseQuery->prepare("select *from animals where id = :id;");
//        databaseQuery->bindValue(":id",data);
//        databaseQuery->exec();
//        }
//        break;
//        case 2:{

//        databaseQuery->prepare("select *from animals where species = :name;");
//        databaseQuery->bindValue(":name",data);
//        databaseQuery->exec();
//       }
//        break;
//        case 3:{
//        databaseQuery->prepare("select *from animals where health = :health;");
//        databaseQuery->bindValue(":health",data);
//        databaseQuery->exec();

//       }
//       break;
//       case 4:{
//        databaseQuery->prepare("select *from animals where arrived = :arrived;");
//        databaseQuery->bindValue(":arrived",ui->lineEdit->text());
//        databaseQuery->exec();

//      }
//       break;
//        case 5:{
//        databaseQuery->prepare("select *from animals where diet = :diet;");
//        databaseQuery->bindValue(":diet",ui->lineEdit->text());
//        databaseQuery->exec();
//       }
//       break;
//       case 6:{

//        databaseQuery->prepare("select *from animals where price = :price;");
//        databaseQuery->bindValue(":price",ui->lineEdit->text().toDouble());
//        databaseQuery->exec();
//      }
//       break;
//       default:{

//      }

//    }
//    databaseModel->setQuery(*databaseQuery);
//    searchDB.closeConnection();
}
