#ifndef AUTORISATIONWINDOW_H
#define AUTORISATIONWINDOW_H

#include <QMainWindow>

namespace Ui {
class autorisationWindow;
}

class autorisationWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit autorisationWindow(QWidget *parent = 0);
    ~autorisationWindow();

private:
    Ui::autorisationWindow *ui;
};

#endif // AUTORISATIONWINDOW_H
