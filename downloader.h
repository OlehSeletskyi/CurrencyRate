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
    Q_PROPERTY(QString mSelectedDate WRITE setSelectedDate)
public:
    explicit Downloader(QObject *parent = nullptr);
    void setModelName(MyListModel *myListModel);
    void setSelectedDate(QString selectedDate);

private slots:
    void download(QDate date);
    void onResult(QNetworkReply *reply);
    void writeModel();

private:
    QNetworkAccessManager *networkManager;
    QJsonArray jsonArray;
    QJsonArray jsonArrayPreviousDay;
    MyListModel *listModel;
    QDate mPreviousDate;
    QDate mSelectedDate;
};

#endif // DOWNLOADER_H
