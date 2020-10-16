#include "projectDataRequest.h"

ProjectDataRequest::ProjectDataRequest(QNetworkAccessManager *net_acc_manager, const QString& token,
                                       const QString& proj_id)
{
    QNetworkRequest request(QUrl("https://api.quwi.com/v2/projects-manage/" + proj_id));
    request.setRawHeader("Authorization", ("Bearer " + token).toUtf8());
    setReply(net_acc_manager->get(request));
}

void ProjectDataRequest::dataReceived(QJsonObject& obj)
{
    emit projectDataReceived(obj);
}
