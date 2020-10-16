#ifndef PROJECTSLISTREQUEST_H
#define PROJECTSLISTREQUEST_H

#include "httpRequest.h"

class ProjectsListRequest : public HttpRequest
{
    Q_OBJECT

public:
    ProjectsListRequest(QNetworkAccessManager *net_acc_manager, const QString& token);

private:
    void dataReceived(QJsonObject& obj) override;

signals:
    void projectsListReceived(QJsonArray proj_list);
};

#endif // PROJECTSLISTREQUEST_H
