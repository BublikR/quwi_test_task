#ifndef LOGOUTREQUEST_H
#define LOGOUTREQUEST_H

#include "httpRequest.h"

class LogoutRequest : public HttpRequest
{
    Q_OBJECT

public:
    LogoutRequest(QNetworkAccessManager *net_acc_manager);
};

#endif // LOGOUTREQUEST_H
