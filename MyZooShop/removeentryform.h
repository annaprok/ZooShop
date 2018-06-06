#ifndef REMOVEENTRYFORM_H
#define REMOVEENTRYFORM_H

#include <QWidget>

namespace Ui {
class removeentryform;
}

class removeentryform : public QWidget
{
    Q_OBJECT

public:
    explicit removeentryform(QWidget *parent = 0);
    ~removeentryform();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::removeentryform *ui;
};

#endif // REMOVEENTRYFORM_H
