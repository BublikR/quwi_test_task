#ifndef PROJECTDATAREQUEST_H
#define PROJECTDATAREQUEST_H

#include "httpRequest.h"

class ProjectDataRequest : public HttpRequest

{
    Q_OBJECT
    int id;

public:
    ProjectDataRequest(QNetworkAccessManager *net_acc_manager, const QString& token, const QString& proj_id);

private:
    void dataReceived(QJsonObject& obj) override;

signals:
    void projectDataReceived(QJsonObject obj);
};

#endif // PROJECTDATAREQUEST_H
