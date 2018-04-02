#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QJsonArray>
#include <QNetworkAccessManager>

class MyListModel;

class Downloader : public QObject
{
    Q_OBJECT
public:
    explicit Downloader(QObject *parent = nullptr);
    void setModelName(MyListModel *myListModel);

private slots:
    void onResult(QNetworkReply *reply);
    void writeModel();

private:
    QNetworkAccessManager *networkManager;
    QJsonArray jsonArray;
    MyListModel *listModel;
};

#endif // DOWNLOADER_H
