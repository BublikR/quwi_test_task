#ifndef LOGINREQUEST_H
#define LOGINREQUEST_H

#include "httpRequest.h"

class LoginRequest : public HttpRequest
{
    Q_OBJECT

public:
    LoginRequest(QNetworkAccessManager *net_acc_manager, const QString& login, const QString& pass);

private:
    void dataReceived(QJsonObject& obj) override;

signals:
    void tokenReceived(QString token);
};

#endif // LOGINREQUEST_H
