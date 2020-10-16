#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QToolBar>
#include <QSizePolicy>
#include <QStackedWidget>

#include "loginView.h"
#include "projectsListView.h"
#include "projectView.h"
#include "networkManage.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QStackedWidget *set_of_views;
    QToolBar *toolbar;
    QAction *projects_action;
    QAction *logout_action;
    LoginView *login_view;
    ProjectsListView *projects_view;
    ProjectView *project_view;
    NetworkManage *net_manage;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

    void toolBarInit();

public slots:
    void prepareProjectsView();
    void showProjectsView(QJsonArray proj_list);
    void prepareProjectView(const QString& id);
    void showProjectView(QJsonObject obj);
    void showLoginView();

};
#endif // MAINWINDOW_H
