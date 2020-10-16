#include "projectDataRequest.h"

ProjectDataRequest::ProjectDataRequest(QNetworkAccessManager *net_acc_manager, const QString& token,
                                       const QString& proj_id)
{
    id = proj_id.toInt();
    QNetworkRequest request(QUrl("https://api.quwi.com/v2/projects-manage/index"));
    request.setRawHeader("Authorization", ("Bearer " + token).toUtf8());
    setReply(net_acc_manager->get(request));
}

void ProjectDataRequest::dataReceived(QJsonObject& obj)
{
    QJsonArray proj_array = obj["projects"].toArray();
    for(auto i = proj_array.begin(); i != proj_array.end(); i++)
    {
        if(i->toObject()["id"].toInt() == id)
        {
            emit projectDataReceived(i->toObject());
            break;
        }
    }
}
