#ifndef DOWNLOADER_H
#define DOWNLOADER_H

#include <QObject>
#include <QJsonArray>
#include <QNetworkAccessManager>
#include <QDate>

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
//    double roundDouble(double doValue, int nPrecision);

private:
    QNetworkAccessManager *networkManager;
    QJsonArray jsonArray;
    QJsonArray jsonArrayPreviousDay;
    MyListModel *listModel;
    QDate mDate;

};

#endif // DOWNLOADER_H
