#include "downloader.h"
#include "qlistmodel.h"
#include "coin.h"

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QUrlQuery>
#include <QNetworkReply>
#include <QUrl>
#include <QString>
#include <QDebug>
#include <QQmlListProperty>

Downloader::Downloader(QObject *parent) : QObject(parent)
{
    networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
    networkManager->get(QNetworkRequest(QUrl("https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json")));
}

void Downloader::onResult(QNetworkReply *reply)
{
    if(!reply->error())
    {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());

        QJsonArray root = document.array();
        for(int i = 0; i < root.count(); i++)
        {
            QJsonObject subtree = root.at(i).toObject();
            qDebug() << "currency: " << subtree.value("txt").toString() + " = " + subtree.value("rate").toDouble();
            Coin *coin = new Coin(this);
            coin->setName(subtree.value("txt").toString());
            coin->setShortName(subtree.value("cc").toString());
            coin->setRate(subtree.value("rate").toString());
//            QListModel::appendData( , coin);
        }
    }
    reply->deleteLater();
}
