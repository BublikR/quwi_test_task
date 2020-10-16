#include "httpRequest.h"

HttpRequest::HttpRequest(QObject *parent)
    : QObject(parent)
{}

void HttpRequest::setReply(QNetworkReply *reply)
{
    reply->setParent(this);
    this->reply = reply;
    connect(reply, &QNetworkReply::readyRead, this, &HttpRequest::requestFinished);
}

void HttpRequest::setReplyForImage(QNetworkReply *reply)
{
    reply->setParent(this);
    this->reply = reply;
    connect(reply, &QNetworkReply::readyRead, this, &HttpRequest::requestForImageFinished);
}

void HttpRequest::requestFinished()
{
    QString ans = reply->readAll();
    qDebug() << ans;
    QJsonDocument doc = QJsonDocument::fromJson(ans.toUtf8());
    QJsonObject obj = doc.object();
    emit dataReceived(obj);
}

void HttpRequest::requestForImageFinished()
{
    QJsonObject obj;
    emit dataReceived(obj);
}
