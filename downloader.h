#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QNetworkAccessManager>

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);

private slots:
    void onResult(QNetworkReply *reply);

private:
    QNetworkAccessManager *networkManager;

};

#endif // DOWNLOADER_H
