#include "loginView.h"

LoginView::LoginView(MainWindow *main_window, NetworkManage *net_manage)
    : main_window(main_window),
      net_manage(net_manage),
      login_box(new QVBoxLayout(this)),
      login_label(new QLabel("LOGIN")),
      login_line_edit(new QLineEdit),
      pass_line_edit(new QLineEdit),
      login_button(new QPushButton("LOGIN")),
      error_label(new QLabel)
{
    login_label->setFixedSize(50, 30);
    login_line_edit->setFixedSize(250, 30);
    pass_line_edit->setFixedSize(250, 30);
    login_button->setFixedSize(85, 30);
    error_label->setFixedSize(250, 30);

    login_label->setStyleSheet("font-weight: bold");
    login_line_edit->setPlaceholderText("Email");
    pass_line_edit->setPlaceholderText("Password");
    pass_line_edit->setEchoMode(QLineEdit::Password);

    login_line_edit->setStyleSheet("QLineEdit { border: 1px solid grey; border-radius: 5px; }");
    pass_line_edit->setStyleSheet("QLineEdit { border: 1px solid grey; border-radius: 5px; }");
    login_button->setStyleSheet("QPushButton { color: white; background-color: darkblue; border-radius: 5px; }");
    error_label-> setStyleSheet("color: red");

    login_button->setDefault(true);

    login_box->addWidget(login_label);
    login_box->addWidget(login_line_edit);
    login_box->addWidget(pass_line_edit);
    login_box->addWidget(login_button);
    login_box->addWidget(error_label);
    login_box->setAlignment(Qt::AlignCenter);

    connect(login_button, &QPushButton::clicked, this, &LoginView::loginClicked);
    connect(net_manage, &NetworkManage::loginErrorReceived, this, &LoginView::loginError);
}

void LoginView::loginClicked()
{
    net_manage->enterLogin(login_line_edit->text(), pass_line_edit->text());
}

void LoginView::loginError(QString error)
{
    error_label->setText(error);
}
