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
    void errorReceived(QString error) override;

signals:
    void tokenReceived(QString token);
    void errorSignal(QString error);
};

#endif // LOGINREQUEST_H
