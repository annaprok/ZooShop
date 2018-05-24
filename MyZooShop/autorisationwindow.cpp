#include "autorisationwindow.h"
#include "ui_autorisationwindow.h"

autorisationWindow::autorisationWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::autorisationWindow)
{
    ui->setupUi(this);

    QPixmap bkgnd("../cat.jpg");
    bkgnd = bkgnd.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, bkgnd);
    this->setPalette(palette);
}

autorisationWindow::~autorisationWindow()
{
    delete ui;
}
