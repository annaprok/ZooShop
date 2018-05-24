#ifndef SELLERWINDOW_H
#define SELLERWINDOW_H

#include <QMainWindow>

namespace Ui {
class SellerWindow;
}

class SellerWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SellerWindow(QWidget *parent = 0);
    ~SellerWindow();

private:
    Ui::SellerWindow *ui;
};

#endif // SELLERWINDOW_H
