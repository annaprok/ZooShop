#ifndef EDITGOODSFORM_H
#define EDITGOODSFORM_H

#include <QWidget>

namespace Ui {
class EditGoodsForm;
}

class EditGoodsForm : public QWidget
{
    Q_OBJECT

public:
    int toEdit;
    explicit EditGoodsForm(QWidget *parent = 0);
    ~EditGoodsForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::EditGoodsForm *ui;
};

#endif // EDITGOODSFORM_H
