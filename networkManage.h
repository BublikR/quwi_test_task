#ifndef NETWORKMANAGE_H
#define NETWORKMANAGE_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QUrlQuery>
#include <QJsonObject>
#include <QJsonDocument>
#include <QJsonArray>
#include <QLabel>

#include "loginRequest.h"
#include "projectsListRequest.h"
#include "projectDataRequest.h"
#include "downloadImageRequest.h"
#include "setProjectNameRequest.h"

class NetworkManage : public QObject
{
    Q_OBJECT

    QString token;
    QNetworkAccessManager *net_acc_manager;

public:
    NetworkManage(QObject *parent = nullptr);
    void enterLogin(const QString& login, const QString& pass);
    void getProjectsList();
    void getProjectData(const QString& id);
    void downloadImage(QLabel *label, const QString& url, const QSize& size);
    void setProjectName(const QString& id, const QJsonObject& obj);

signals:
    void signIn();
    void signOut();
    void projectsListReceived(QJsonArray proj_list);
    void projectDataReceived(QJsonObject obj);
    void authorizedChanged(bool authorized);

private slots:
    void  tokenReceived(const QString& token);
};

#endif // NETWORKMANAGE_H
