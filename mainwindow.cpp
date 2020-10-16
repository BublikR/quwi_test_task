#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent),
      net_manage(new NetworkManage(this)),
      set_of_views(new QStackedWidget(this)),
      toolbar(addToolBar("Main toolbar")),
      ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    login_view = new LoginView(this, net_manage);
    projects_view = new ProjectsListView(this, net_manage);
    project_view = new ProjectView(this, net_manage);

    toolBarInit();

    set_of_views->setStyleSheet("background-color: white");
    set_of_views->addWidget(login_view);
    set_of_views->addWidget(projects_view);
    set_of_views->addWidget(project_view);

    set_of_views->setCurrentWidget(login_view);

    toolbar->setVisible(false);
    setCentralWidget(set_of_views);

    connect(net_manage, &NetworkManage::signIn, this, &MainWindow::prepareProjectsView);
    connect(net_manage, &NetworkManage::projectsListReceived, this, &MainWindow::showProjectsView);
    connect(net_manage, &NetworkManage::projectDataReceived, this, &MainWindow::showProjectView);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::toolBarInit()
{
    QWidget *spacer = new QWidget();
    spacer->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
    toolbar->addWidget(spacer);

    projects_action = new QAction("PROJECTS", toolbar);
    logout_action = new QAction("LOGOUT", toolbar);

    toolbar->addAction(projects_action);
    toolbar->addAction(logout_action);

    connect(projects_action, &QAction::triggered, this, &MainWindow::prepareProjectsView);
    connect(logout_action, &QAction::triggered, this, &MainWindow::logOut);
}

void MainWindow::prepareProjectsView()
{
    net_manage->getProjectsList();
}

void MainWindow::showProjectsView(QJsonArray proj_list)
{
    toolbar->setVisible(true);
    projects_view->view(proj_list);
    set_of_views->setCurrentWidget(projects_view);
}

void MainWindow::prepareProjectView(const QString& id)
{
    net_manage->getProjectData(id);
}

void MainWindow::showProjectView(QJsonObject obj)
{
    toolbar->setVisible(true);
    project_view->view(obj);
    set_of_views->setCurrentWidget(project_view);
}

void MainWindow::logOut()
{
    toolbar->setVisible(false);
    set_of_views->setCurrentWidget(login_view);
    net_manage->exitLogin();
}
