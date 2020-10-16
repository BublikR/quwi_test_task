#include "projectsListRequest.h"

ProjectsListRequest::ProjectsListRequest(QNetworkAccessManager *net_acc_manager, const QString& token)
{
    QNetworkRequest request(QUrl("https://api.quwi.com/v2/projects-manage/index"));
    request.setRawHeader("Authorization", ("Bearer " + token).toUtf8());
    setReply(net_acc_manager->get(request));
}

void ProjectsListRequest::dataReceived(QJsonObject& obj)
{
    emit projectsListReceived(obj["projects"].toArray());
}
