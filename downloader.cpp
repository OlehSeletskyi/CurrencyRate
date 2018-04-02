#include "downloader.h"
#include "mylistmodel.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QDebug>

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::writeModel);
    networkManager->get(QNetworkRequest(QUrl("https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json")));
}

void Downloader::onResult(QNetworkReply *reply)
{
    if(!reply->error())
    {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        jsonArray = document.array();
    }
    reply->deleteLater();
}

void Downloader::setModelName(MyListModel *myListModel)
{
    listModel = myListModel;
}

void Downloader::writeModel() {
    for(int i = 0; i < jsonArray.count(); i++)
    {
        Coin coin;
        QJsonObject subtree = jsonArray.at(i).toObject();
        coin.setName(subtree.value("txt").toString());
        coin.setShortName(subtree.value("cc").toString());
        coin.setRate(QString::number(subtree.value("rate").toDouble()));
        listModel->addCoin(coin);
    }
}
