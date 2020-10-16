#include "networkManage.h"

NetworkManage::NetworkManage(QObject *parent)
    : QObject(parent),
      token(QString("")),
      net_acc_manager(new QNetworkAccessManager(this))
//      authorized(false)
{}

void NetworkManage::enterLogin(const QString& login, const QString& pass)
{
    LoginRequest *request = new LoginRequest(net_acc_manager, login, pass);
    connect(request, &LoginRequest::tokenReceived, this, &NetworkManage::tokenReceived);
    connect(request, &LoginRequest::tokenReceived, request, &LoginRequest::deleteLater);
}

void NetworkManage::getProjectsList()
{
    ProjectsListRequest *request = new ProjectsListRequest(net_acc_manager, token);
    connect(request, &ProjectsListRequest::projectsListReceived, this, &NetworkManage::projectsListReceived);
    connect(request, &ProjectsListRequest::projectsListReceived, request, &ProjectsListRequest::deleteLater);
}

void NetworkManage::getProjectData(const QString &id)
{
    ProjectDataRequest *request = new ProjectDataRequest(net_acc_manager, token, id);
    connect(request, &ProjectDataRequest::projectDataReceived, this, &NetworkManage::projectDataReceived);
    connect(request, &ProjectDataRequest::projectDataReceived, request, &ProjectDataRequest::deleteLater);
}

void NetworkManage::downloadImage(QLabel *label, const QString& url, const QSize& size)
{
    DownloadImageRequest *request = new DownloadImageRequest(net_acc_manager, label, url, size);
    connect(request, &DownloadImageRequest::imageReady, request, &DownloadImageRequest::deleteLater);
}

void NetworkManage::setProjectName(const QString& id, const QJsonObject& obj)
{
    SetProjectNameRequest(net_acc_manager, token, id, obj);
}


void NetworkManage::tokenReceived(const QString& a_token)
{
   token = a_token;
   if(token != "")
       emit signIn();
}
