#ifndef DOWNLOADIMAGEREQUEST_H
#define DOWNLOADIMAGEREQUEST_H

#include <QLabel>
#include <QImage>
#include <QImageReader>
#include <QPixmap>

#include "httpRequest.h"

class DownloadImageRequest : public HttpRequest
{
    Q_OBJECT

    QLabel* label;
    QSize size;

public:
    DownloadImageRequest(QNetworkAccessManager *net_acc_manager, QLabel *label,
                         const QString& url, const QSize& size);

private:
    void dataReceived(QJsonObject& obj) override;

signals:
    void imageReady();
};

#endif // DOWNLOADIMAGEREQUEST_H
