#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <coin.h>

//#include <QObject>
//#include <QQmlListProperty>

class MyListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        ShortNameRole,
        RateRole
    };

    MyListModel(QObject *parent = 0);

    void addCoin(const Coin &coin);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

protected:
    QHash<int,QByteArray> roleNames() const;

private:
    QList<Coin> mCoins;
};

#endif // MYLISTMODEL_H
