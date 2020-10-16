#include "downloadImageRequest.h"

DownloadImageRequest::DownloadImageRequest(QNetworkAccessManager *net_acc_manager, QLabel *label,
                                           const QString& url, const QSize& size)
    : label(label),
      size(size)
{
    QNetworkRequest request;
    request.setUrl(QUrl(url));
    setReplyForImage(net_acc_manager->get(request));
}

void DownloadImageRequest::dataReceived(QJsonObject &obj)
{
    QImageReader imageReader(reply);
    imageReader.setAutoDetectImageFormat(true);
    QImage image = imageReader.read();
    image = image.scaled(size, Qt::KeepAspectRatio);
    label->setPixmap(QPixmap::fromImage(image));
    emit imageReady();
}
