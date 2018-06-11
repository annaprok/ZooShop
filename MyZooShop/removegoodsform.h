#ifndef REMOVEGOODSFORM_H
#define REMOVEGOODSFORM_H

#include <QWidget>

namespace Ui {
class RemoveGoodsForm;
}

class RemoveGoodsForm : public QWidget
{
    Q_OBJECT

public:
    explicit RemoveGoodsForm(QWidget *parent = 0);
    ~RemoveGoodsForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RemoveGoodsForm *ui;
};

#endif // REMOVEGOODSFORM_H
