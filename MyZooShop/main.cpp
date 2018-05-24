#include "mainwindow.h"
#include "adminwindow.h"
#include "sellerwindow.h"
#include "login.h"
#include <QApplication>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //QTextCodec::setCodecForTr(QTextCodec::codecForLocale());

        MainWindow w;
        LogIn login;
        do
        {
            if (login.exec() == LogIn::Rejected)
                return 0;
            if(login.user()=="admin"){
                AdminWindow w;
                w.show();
            }
            else if(login.user()=="seller"){
                SellerWindow w ;
                w.show();
            }

        }
        while (!w.login(login.userName(), login.password()));

//    MainWindow w;
//    w.show();

    return a.exec();
}
