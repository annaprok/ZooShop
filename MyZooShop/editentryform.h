#ifndef EDITENTRYFORM_H
#define EDITENTRYFORM_H

#include <QWidget>


namespace Ui {
class editentryForm;
}

class editentryForm : public QWidget
{
    Q_OBJECT

public:
    int toEdit;
    explicit editentryForm(QWidget *parent = 0);
    ~editentryForm();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::editentryForm *ui;
    QByteArray image;
};

#endif // EDITENTRYFORM_H
