#ifndef ADDANIMALDIALOG_H
#define ADDANIMALDIALOG_H

#include <QDialog>

namespace Ui {
class AddAnimalDialog;
}

class AddAnimalDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddAnimalDialog(QWidget *parent = 0);
    ~AddAnimalDialog();

private:
    Ui::AddAnimalDialog *ui;
};

#endif // ADDANIMALDIALOG_H
