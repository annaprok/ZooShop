#ifndef ADMINWINDOW_H
#define ADMINWINDOW_H

#include <QMainWindow>
#include "addform.h"
#include "editentryform.h"
#include "databaseconnection.h"
#include "removeentryform.h"

namespace Ui {
class AdminWindow;
}

class AdminWindow : public QMainWindow
{
    Q_OBJECT

public:
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

private:
    AddForm addAnimal;
    editentryForm editDBentry;
removeentryform removeEntry;
private:
    Ui::AdminWindow *ui;
};

#endif // ADMINWINDOW_H
