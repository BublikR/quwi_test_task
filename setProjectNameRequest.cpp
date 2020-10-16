#include "setProjectNameRequest.h"

SetProjectNameRequest::SetProjectNameRequest(QNetworkAccessManager *net_acc_manager, const QString& token,
                                             const QString& id, const QJsonObject& obj)
{
    QNetworkRequest request(QUrl("https://api.quwi.com/v2/projects-manage/update?id=" + id));
    request.setRawHeader("Authorization", ("Bearer " + token.toUtf8()));
    QUrlQuery args;
    for(auto i = obj.begin(); i != obj.end(); i++)
        args.addQueryItem(i.key(), i.value().toString());
    net_acc_manager->post(request, args.query().toUtf8());
}
