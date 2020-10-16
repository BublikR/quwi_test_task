#include "logoutRequest.h"

LogoutRequest::LogoutRequest(QNetworkAccessManager *net_acc_manager)
{
    QUrlQuery args;
    args.addQueryItem("anywhere", "false");
    net_acc_manager->post(QNetworkRequest(QUrl("https://api.quwi.com/v2/auth/logout")), args.query().toUtf8());
}
