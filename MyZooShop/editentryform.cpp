#include "editentryform.h"
#include "ui_editentryform.h"
#include "databaseconnection.h"
#include <QtSql>
#include <QtWidgets>
using namespace std;

editentryForm::editentryForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::editentryForm)
{
    ui->setupUi(this);

}

editentryForm::~editentryForm()
{
    delete ui;
}

void editentryForm::on_pushButton_clicked()
{
    connectDatabase editDB;
    bool isCorrectEntry;

    editDB.openConnection();

//    if(ui->lineEdit->text() == ""){
//        QMessageBox::about(this,"No Key!","Please Enter № of the record to be updated!");
//    }
//    else
    {
            QSqlQuery editQry;


            if(ui->lineEdit_5->text() == "" && ui->lineEdit_2->text() == "" && ui->lineEdit_3->text() == "" && ui->doubleSpinBox->value() == 0){
                QMessageBox::about(this,"Empty values!","Please Enter Values to be Updated!");
            }


//            if(ui->lineEdit_4->text()!=""){
//              editQry.prepare("update animals set arrived = :newyear where id = :isbn");
//              editQry.bindValue(":newyear",ui->lineEdit_4->text());
//              editQry.bindValue(":isbn",ui->lineEdit->text());
//              isCorrectEntry = editQry.exec();
//            }

//            if(ui->lineEdit_3->text()!=""){
//              editQry.prepare("update animals set health = :health where id = :isbn");
//              editQry.bindValue(":health",ui->lineEdit_3->text());
//              editQry.bindValue(":isbn",ui->lineEdit->text());
//              isCorrectEntry = editQry.exec();
//            }

//            if(ui->lineEdit_2->text()!=""){
//              editQry.prepare("update animals set species = :newname where id = :isbn");
//              editQry.bindValue(":newname",ui->lineEdit_2->text());
//              editQry.bindValue(":isbn",ui->lineEdit->text());
//              isCorrectEntry = editQry.exec();
//            }

//            if(ui->lineEdit_5->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
//              editQry.prepare("update animals set diet = :newisbn where id = :isbn");
//              editQry.bindValue(":newisbn",ui->lineEdit_5->text());
//              editQry.bindValue(":isbn",ui->lineEdit->text());
//              isCorrectEntry = editQry.exec();
//            }
//            if(ui->lineEdit_6->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
//              editQry.prepare("update animals set notice = :newisbn where id = :isbn");
//              editQry.bindValue(":newisbn",ui->lineEdit_6->text());
//              editQry.bindValue(":isbn",ui->lineEdit->text());
//              isCorrectEntry = editQry.exec();
//            }
//            if(ui->doubleSpinBox->value()!=0){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
//              editQry.prepare("update animals set price = :newisbn where id = :isbn");
//              editQry.bindValue(":newisbn",ui->doubleSpinBox->value());
//              editQry.bindValue(":isbn",ui->lineEdit->text());
//              isCorrectEntry = editQry.exec();
//            }
//            if(image!=0){
//                 editQry.prepare("update animals set photo = :photo where id = :isbn");
//                 editQry.bindValue(":photo",image, QSql::In | QSql::Binary);
//                 editQry.bindValue(":isbn",ui->lineEdit->text());
//                 isCorrectEntry = editQry.exec();
//            }
            if(ui->lineEdit_4->text()!=""){
                          editQry.prepare("update animals set arrived = :newyear where id = :isbn");
                          editQry.bindValue(":newyear",ui->lineEdit_4->text());
                          editQry.bindValue(":isbn",toEdit);
                          isCorrectEntry = editQry.exec();
                        }

                        if(ui->lineEdit_3->text()!=""){
                          editQry.prepare("update animals set health = :health where id = :isbn");
                          editQry.bindValue(":health",ui->lineEdit_3->text());
                          editQry.bindValue(":isbn",toEdit);
                          isCorrectEntry = editQry.exec();
                        }

                        if(ui->lineEdit_2->text()!=""){
                          editQry.prepare("update animals set species = :newname where id = :isbn");
                          editQry.bindValue(":newname",ui->lineEdit_2->text());
                          editQry.bindValue(":isbn",toEdit);
                          isCorrectEntry = editQry.exec();
                        }

                        if(ui->lineEdit_5->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
                          editQry.prepare("update animals set diet = :newisbn where id = :isbn");
                          editQry.bindValue(":newisbn",ui->lineEdit_5->text());
                          editQry.bindValue(":isbn",toEdit);
                          isCorrectEntry = editQry.exec();
                        }
                        if(ui->lineEdit_6->text()!=""){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
                          editQry.prepare("update animals set notice = :newisbn where id = :isbn");
                          editQry.bindValue(":newisbn",ui->lineEdit_6->text());
                          editQry.bindValue(":isbn",toEdit);
                          isCorrectEntry = editQry.exec();
                        }
                        if(ui->doubleSpinBox->value()!=0){                                                 //ISBN is updated at end to prevent the wrong referencing of ISBN in updting other entries.
                          editQry.prepare("update animals set price = :newisbn where id = :isbn");
                          editQry.bindValue(":newisbn",ui->doubleSpinBox->value());
                          editQry.bindValue(":isbn",toEdit);
                          isCorrectEntry = editQry.exec();
                        }
                        if(image!=0){
                             editQry.prepare("update animals set photo = :photo where id = :isbn");
                             editQry.bindValue(":photo",image, QSql::In | QSql::Binary);
                             editQry.bindValue(":isbn",toEdit);
                             isCorrectEntry = editQry.exec();
                        }
    }

    editDB.closeConnection();

    if(isCorrectEntry){
        QMessageBox::about(this,"Upation Successful","Entry Updated Successfully!");
    }
    else if (ui->lineEdit->text() != ""){
        QMessageBox::about(this,"Failed!","Error in Value or Input type!");
    }
    image=0;
    ui->lineEdit->setText("");
    ui->lineEdit_2->setText("");
    ui->lineEdit_3->setText("");
    ui->lineEdit_4->setText("");
    ui->lineEdit_5->setText("");
}

void editentryForm::on_pushButton_2_clicked()
{
    this->close();
}
string get_ext (const string& st) {
    size_t pos = st.rfind('.');
    if (pos <= 0) return "";
    return st.substr(pos+1, string::npos);
}
void editentryForm::on_pushButton_3_clicked()
{
    QString str=QFileDialog::getOpenFileName(this,tr("Load file"),"",tr("Image file(*.png *.jpg *.jpeg)"));
    //string x=get_ext(str);
    QFile file(str);
    if (!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::about(this,"No Image!","Load file error");
        return;
    }

    QMessageBox::about(this,"Congrats!","Image loaded");
    QByteArray inByteArray = file.readAll();
//    QBuffer inBuffer( &inByteArray );
//        inBuffer.open( QIODevice::WriteOnly );
//    if(get_ext(str)=="png"){

//        inPixmap.save( &inBuffer, "PNG" );
//    }
//    else if(get_ext(str)=="jpg"){
//         inPixmap.save( &inBuffer, "JPG" );
//    }
//    else if(get_ext(str)=="jpeg"){
//         inPixmap.save( &inBuffer, "JPEG" );
//    }


        image=inByteArray;
}
