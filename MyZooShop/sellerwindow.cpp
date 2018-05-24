#include "sellerwindow.h"
#include "ui_sellerwindow.h"

SellerWindow::SellerWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SellerWindow)
{
    ui->setupUi(this);
}

SellerWindow::~SellerWindow()
{
    delete ui;
}
