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
#include <math.h>

Downloader::Downloader(QObject *parent) : QObject(parent)
{
     networkManager = new QNetworkAccessManager(this);
     connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
     //    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::writeModel);
}

void Downloader::setModelName(MyListModel *myListModel)
{
    listModel = myListModel;
}

void Downloader::setSelectedDate(QString strDate)
{
    listModel->clearModel();
    qDebug() << "strDate" << strDate;
    strDate = strDate.left(strDate.indexOf('T'));
    mSelectedDate = QDate::fromString(strDate, "yyyy-MM-dd");

    mPreviousDate = QDate();
    qDebug() << "setSelectedDate->";
    download(mSelectedDate);
}

QString Downloader::selectedDate() const
{
    return mSelectedDate.toString("dd.MM.yyyy");
}

void Downloader::download(QDate date)
{
    QString strDate = date.toString("yyyyMMdd");
    qDebug() << "strDate" << strDate;
    networkManager->get(QNetworkRequest(QUrl("https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?date="
                                             + strDate + "&json")));
}

void Downloader::onResult(QNetworkReply *reply)
{
    qDebug() << "onResult";
    if(!reply->error())
    {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        if(mPreviousDate.toString().isEmpty())
        {
            jsonArray = document.array();
        }
        else
        {
            jsonArrayPreviousDay = document.array();
        }
        qDebug() << "jsonArray" << document;
    }
    reply->deleteLater();
    writeModel();
//    for (int i = 0; i < listModel->rowCount(); ++i)
//    {
//        QModelIndex modelIndex;
//        modelIndex.child(i, 0);
////        qDebug() << "Coin: " << i << " " << listModel->data(modelIndex, MyListModel::Roles::NameRole);
//    }
}



void Downloader::writeModel() {
//    qDebug() << "writeModel" << mPreviousDate << jsonArray << jsonArrayPreviousDay;
    if(mPreviousDate.toString().isEmpty())
    {
        mPreviousDate = mSelectedDate.addDays(-1);
        download(mPreviousDate);
    }
    else
    {
        for(int i = 0; i < jsonArray.count(); i++)
        {
            Coin coin;
            double rateDifference = 0;
            QJsonObject subtree = jsonArray.at(i).toObject();
            for(int j = 0; j < jsonArrayPreviousDay.count(); j++)
            {
                QJsonObject subtreePreviousDay = jsonArrayPreviousDay.at(j).toObject();
                if(subtree.value("cc").toString() == subtreePreviousDay.value("cc").toString())
                {
                    rateDifference = subtree.value("rate").toDouble() - subtreePreviousDay.value("rate").toDouble();
                }
            }
            coin.setName(subtree.value("txt").toString());
            coin.setShortName(subtree.value("cc").toString());
            QString rate = QString::number(subtree.value("rate").toDouble(), 'f', 5);
            coin.setRate(rate);
            QString rDifference = QString::number(rateDifference, 'f', 2);
            coin.setRateDifference(rDifference);
            listModel->addCoin(coin);
        }
    }
    qDebug() << "rowCount" << listModel->rowCount();
}

QObject *Downloader::getListModel() const
{
    return listModel;
}
