#ifndef SETPROJECTNAMEREQUEST_H
#define SETPROJECTNAMEREQUEST_H

#include "httpRequest.h"

class SetProjectNameRequest : public HttpRequest
{
    Q_OBJECT

public:
    SetProjectNameRequest(QNetworkAccessManager *net_acc_manager, const QString& token,
                          const QString& id, const QJsonObject& obj);
};

#endif // SETPROJECTNAMEREQUEST_H
