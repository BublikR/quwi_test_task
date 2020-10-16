#include "projectView.h"
#include "mainWindow.h"

ProjectView::ProjectView(MainWindow *main_window, NetworkManage *net_manage)
    : QWidget(main_window),
      main_window(main_window),
      net_manage(net_manage),
      active_label(new QLabel("Active")),
      name_label(new QLabel("Name")),
      users_label(new QLabel("Users")),
      main_image_label(new QLabel),
      add_me_as_watcher_label(new QLabel("Add me as watcher to tickets created by other")),
      name_edit(new QLineEdit),
      active_chbox(new QCheckBox),
      add_me_as_watcher_chbox(new QCheckBox),
      ok_button(new QPushButton("OK")),
      grid(new QGridLayout(this))
{
    main_image_label->setFixedSize(80, 80);
    active_label->setFixedSize(80, 40);
    active_chbox->setFixedSize(80, 40);
    active_chbox->setCheckable(true);
    active_chbox->setStyleSheet("QCheckBox::indicator:checked { image: url(:/img/check_act.png); width: 49px; height: 27; }");
    name_label->setFixedSize(80, 40);
    name_edit->setFixedSize(300, 40);
    name_edit->setStyleSheet("QLineEdit { border: 1px solid grey; border-radius: 5px; }");
    ok_button->setFixedSize(50, 40);
    ok_button->setStyleSheet("QPushButton { color: white; background-color: darkblue; border-radius: 5px; }");
    add_me_as_watcher_chbox->setFixedSize(80, 40);
    add_me_as_watcher_chbox->setCheckable(true);
    add_me_as_watcher_chbox->setStyleSheet("QCheckBox::indicator:checked { image: url(:/img/check_act.png);"
                                           "width: 49px; height: 27; }");
    add_me_as_watcher_label->setFixedSize(450, 40);

    grid->addWidget(active_label, 0, 0);
    grid->addWidget(active_chbox, 0, 1, 1, 2);
    grid->addWidget(main_image_label, 0, 3, 2, 1);
    grid->addWidget(name_label, 1, 0);
    grid->addWidget(name_edit, 1, 1);
    grid->addWidget(ok_button, 1, 2);
    grid->addWidget(add_me_as_watcher_chbox, 2, 0);
    grid->addWidget(add_me_as_watcher_label, 2, 1, 1, 3);
    grid->setAlignment(Qt::AlignCenter);

    connect(ok_button, &QPushButton::clicked, this, &ProjectView::okButtonClicked);
}

void ProjectView::view(QJsonObject& obj)
{
    name_edit->setText(obj["name"].toString());
    active_chbox->setChecked(obj["is_active"].toInt() == 1);
    add_me_as_watcher_chbox->setChecked(obj["is_owner_watcher"].toInt() == 1);
    QPixmap pixmap;
    main_image_label->setPixmap(pixmap);
    net_manage->downloadImage(main_image_label, obj["logo_url"].toString(), {80, 80});
}

void ProjectView::okButtonClicked()
{
    QJsonObject obj;
    obj.insert("name", QJsonValue(name_edit->text()));
    net_manage->setProjectName(main_window->property("current_project_id").toString(), obj);
}
