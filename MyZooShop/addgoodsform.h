#ifndef ADDGOODSFORM_H
#define ADDGOODSFORM_H

#include <QWidget>

namespace Ui {
class AddGoodsForm;
}

class AddGoodsForm : public QWidget
{
    Q_OBJECT

public:
    explicit AddGoodsForm(QWidget *parent = 0);
    ~AddGoodsForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::AddGoodsForm *ui;
};

#endif // ADDGOODSFORM_H
