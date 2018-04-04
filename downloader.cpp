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
    networkManager = new QNetworkAccessManager();
    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::onResult);
//    connect(networkManager, &QNetworkAccessManager::finished, this, &Downloader::writeModel);
    networkManager->get(QNetworkRequest(QUrl("https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?json")));
}

void Downloader::onResult(QNetworkReply *reply)
{
    if(!reply->error())
    {
        QJsonDocument document = QJsonDocument::fromJson(reply->readAll());
        if(mDate.toString().isEmpty())
        {
            jsonArray = document.array();
            qDebug() <<"111";
        }
        else
        {
            jsonArrayPreviousDay = document.array();
            qDebug() <<"222";
        }
    }
    reply->deleteLater();
    writeModel();
}

void Downloader::setModelName(MyListModel *myListModel)
{
    listModel = myListModel;
}

void Downloader::writeModel() {

    if(mDate.toString().isEmpty())
    {
        qDebug() << "mdate" << mDate.toString().isEmpty();
        mDate = mDate.currentDate().addDays(-1);
        QString date = mDate.toString("yyyyMMdd");
        qDebug() << "DATE" << date;
        networkManager->get(QNetworkRequest(QUrl("https://bank.gov.ua/NBUStatService/v1/statdirectory/exchange?date="
                                                 + date + "&json")));
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
            coin.setRate(subtree.value("rate").toDouble());
            QString rDifference = QString::number(rateDifference, 'f', 2);
            coin.setRateDifference(rDifference);
            listModel->addCoin(coin);
        }
    }
}

//double roundDouble(double doValue, int nPrecision)
//{
//    static const double doBase = 10.0;
//    double doComplete5, doComplete5i;

//    doComplete5 = doValue * pow(doBase, (double) (nPrecision + 1));

//    if (doValue < 0.0)
//        doComplete5 -= 5.0;
//    else
//        doComplete5 += 5.0;

//    doComplete5 /= doBase;
//    modf(doComplete5, &doComplete5i);

//    return doComplete5i / pow(doBase, (double) nPrecision);
//}

