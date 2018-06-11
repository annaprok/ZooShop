#include "mainwindow.h"
#include "adminwindow.h"
#include "sellerwindow.h"
#include "login.h"
#include <QApplication>
#include <QtSql>
#include <QtWidgets>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //Storage storage(3000,(QHostAddress)"127.0.0.1");
    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());


        //w.show();

        //LogIn login;
        //ogin.show();
        MainWindow w;
        w.storage=new Storage(3000,(QHostAddress)"127.0.0.1");
        w.show();

//        connect( login,
//         SIGNAL (acceptLogin(QString&,QString&,int&)),
//         this,
//         SLOT (slotAcceptUserLogin(QString&,QString&)));
       //login->exec();
//        do
//        {
//            if (login.exec() != LogIn::Accepted)
//                return 0;
//            else if(login.user()=="admin"){
//                AdminWindow w;
//                w.show();
//            }
//            else if(login.user()=="seller"){
//                SellerWindow w ;
//                w.show();
//            }

//        }
//        while (!w.login(login.userName(), login.password()));

//    MainWindow w;
//    w.show();

    return a.exec();
}
