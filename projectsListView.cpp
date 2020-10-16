#include "projectsListView.h"
#include "mainwindow.h"

ProjectsListView::ProjectsListView(MainWindow *main_window, NetworkManage *net_manage)
    : QWidget(main_window),
      main_window(main_window),
      net_manage(net_manage),
      list_of_projects(new QListWidget(this)),
      projects_box(new QVBoxLayout(this))
{
    list_of_projects->setFixedWidth(600);
    projects_box->setAlignment(Qt::AlignCenter);
    projects_box->addWidget(list_of_projects);
    connect(list_of_projects, &QListWidget::itemClicked, this, &ProjectsListView::projectClicked);
}

void ProjectsListView::addProjectToList(QJsonObject obj)
{
    QListWidgetItem *project_item = new QListWidgetItem(list_of_projects);
    project_item->setSizeHint(QSize(30, 100));
    project_item->setData(Qt::UserRole+1, obj["id"].toInt());

    list_of_projects->addItem(project_item);

    QWidget *project = new QWidget();
    list_of_projects->setItemWidget(project_item, project);

    QHBoxLayout *project_box = new QHBoxLayout(project);
    QLabel *project_image_label = new QLabel(project);
    QLabel *project_name_label = new QLabel(obj["name"].toString(), project);
    QLabel *project_active_label = new QLabel(project);
    QLabel *time_this_week_label = new QLabel(QString::number(obj["spent_time_week"].toInt()), project);
    QLabel *time_this_month_label = new QLabel(QString::number(obj["spent_time_month"].toInt()), project);
    QLabel *time_total_label = new QLabel(QString::number(obj["spent_time_all"].toInt()), project);
    QFormLayout *time_form = new QFormLayout();

    net_manage->downloadImage(project_image_label, obj["logo_url"].toString(), {80, 80});

    project_name_label->setStyleSheet("font-weight: bold");

    project_active_label->setText(obj["is_active"].toInt() == 1 ? "Active" : "Not active");
    project_active_label->setStyleSheet(obj["is_active"].toInt() == 1 ? "color: green" : "color: gray");
    project_name_label->setStyleSheet("font-weight: bold");

    time_form->addRow("time this week", time_this_week_label);
    time_form->addRow("this month", time_this_month_label);
    time_form->addRow("total", time_total_label);

    project_box->addWidget(project_image_label);
    project_box->addWidget(project_name_label);
    project_box->addWidget(project_active_label);
    project_box->addLayout(time_form);


}

void ProjectsListView::view(QJsonArray& proj_list)
{
    list_of_projects->clear();
    for(auto i = proj_list.begin(); i != proj_list.end(); i++)
        addProjectToList(i->toObject());
}

void ProjectsListView::projectClicked(QListWidgetItem *item)
{
    int id = item->data(Qt::UserRole + 1).toInt();
    QString id_str = QString::number(id);
    main_window->setProperty("current_project_id", QVariant(id_str));
    main_window->prepareProjectView(id_str);
}
