#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "addform.h"
#include "addclientform.h"
#include "addstaffform.h"
#include "addgoodsform.h"
#include "editentryform.h"
#include "editclientform.h"
#include "editgoodsform.h"
#include "editstaffform.h"
#include "databaseconnection.h"
#include "removeentryform.h"
#include "removeclientform.h"
#include "removegoodsform.h"
#include "removestaffform.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
    int role;
    int Userid;
    int Clientid;
    explicit AdminWindow(QWidget *parent = 0);
    ~AdminWindow();
private slots:
    void on_actionNew_Entry_triggered();

    void on_pushButton_clicked();

    void on_actionEdit_Entry_triggered();

    void on_actionRemove_Entry_triggered();

    void on_actionAbout_Developer_triggered();

    void on_actionAbout_Qt_triggered();

    void on_actionExit_triggered();

    void on_comboTables_highlighted(const QString &arg1);

    void on_pushButton_2_clicked();

    void on_commandLinkButton_clicked();

    void on_checkBox_stateChanged(int arg1);

    void on_tableView_clicked(const QModelIndex &index);

    void on_pushButton_3_clicked();

private:
    AddForm addAnimal;
    AddClientForm AddClient;
    AddStaffForm AddStaff;
    AddGoodsForm AddGoods;

    editentryForm editDBentry;
    EditClientForm EditClient;
    EditStaffForm EditStaff;
    EditGoodsForm EditGoods;

    removeentryform removeEntry;
    RemoveClientForm RemoveClient;
    RemoveGoodsForm RemoveGoods;
    RemoveStaffForm RemoveStaff;
private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
