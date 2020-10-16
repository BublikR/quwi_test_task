#ifndef LOGINVIEW_H
#define LOGINVIEW_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>

#include "networkManage.h"

class MainWindow;

class LoginView : public QWidget
{
    Q_OBJECT

    MainWindow *main_window;
    NetworkManage *net_manage;
    QVBoxLayout *login_box;
    QLabel *login_label;
    QLineEdit *login_line_edit;
    QLineEdit *pass_line_edit;
    QPushButton *login_button;
    QLabel *error_label;

public:
    explicit LoginView(MainWindow *main_window, NetworkManage *net_manage);

private slots:
    void loginClicked();
    void loginError(QString error);
};

#endif // LOGINVIEW_H
