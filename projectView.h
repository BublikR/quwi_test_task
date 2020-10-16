#ifndef PROJECTVIEW_H
#define PROJECTVIEW_H

#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>
#include <QLineEdit>
#include <QJsonObject>

#include "networkManage.h"

class MainWindow;

class ProjectView : public QWidget
{
    Q_OBJECT

    MainWindow *main_window;
    NetworkManage *net_manage;
    QLabel *active_label;
    QLabel *name_label;
    QLabel *users_label;
    QLabel *add_me_as_watcher_label;
    QLabel *main_image_label;
    QLineEdit *name_edit;
    QCheckBox *active_chbox;
    QCheckBox *add_me_as_watcher_chbox;
    QPushButton *ok_button;
    QGridLayout *grid;
    bool processing;

public:
    ProjectView(MainWindow *main_window, NetworkManage *net_manage);
    void view(QJsonObject& obj);

private slots:
    void okButtonClicked();
};

#endif // PROJECTVIEW_H
