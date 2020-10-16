#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <QObject>
#include <QNetworkReply>
#include <QNetworkAccessManager>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QLabel>

class HttpRequest : public QObject
{
    Q_OBJECT
public:
    explicit HttpRequest(QObject* parent = nullptr);

protected:
    QNetworkReply* reply;

    virtual void dataReceived(QJsonObject& obj) {}
    void setReply(QNetworkReply* reply);
    void setReplyForImage(QNetworkReply *reply);

private slots:
    void requestFinished();
    void requestForImageFinished();
};

#endif // HTTPREQUEST_H
