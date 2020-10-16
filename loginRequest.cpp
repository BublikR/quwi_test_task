#include "loginRequest.h"

LoginRequest::LoginRequest(QNetworkAccessManager *net_acc_manager, const QString& login, const QString& pass)
{
    QUrlQuery args;
    args.addQueryItem("email", login);
    args.addQueryItem("password", pass);
    setReply(net_acc_manager->post(QNetworkRequest(QUrl("https://api.quwi.com/v2/auth/login")), args.query().toUtf8()));
}

void LoginRequest::dataReceived(QJsonObject& obj)
{
    QString token = obj["token"].toString();
    emit tokenReceived(token);
}

void LoginRequest::errorReceived(QString error)
{
    emit errorSignal(error);
}
