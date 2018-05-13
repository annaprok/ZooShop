#include "autorisationwindow.h"
#include "ui_autorisationwindow.h"

autorisationWindow::autorisationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::autorisationWindow)
{
    ui->setupUi(this);
}

autorisationWindow::~autorisationWindow()
{
    delete ui;
}
