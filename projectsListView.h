#ifndef PROJECTSVIEW_H
#define PROJECTSVIEW_H

#include <QWidget>
#include <QListWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLabel>
#include <QFormLayout>

#include "networkManage.h"

class MainWindow;

class ProjectsListView : public QWidget
{
    Q_OBJECT

    MainWindow *main_window;
    NetworkManage *net_manage;
    QListWidget *list_of_projects;
    QVBoxLayout *projects_box;

public:
    explicit ProjectsListView(MainWindow *main_window, NetworkManage *net_manage);
    void view(QJsonArray& proj_list);

private:
    void addProjectToList(QJsonObject obj);

private slots:
    void projectClicked(QListWidgetItem* item);
};

#endif // PROJECTSVIEW_H
