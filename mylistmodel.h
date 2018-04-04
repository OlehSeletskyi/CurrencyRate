#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>
#include <coin.h>

class MyListModel : public QAbstractListModel
{
    Q_OBJECT

public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        ShortNameRole,
        RateRole,
        RateDifferenceRole
    };

    MyListModel(QObject *parent = 0);

    void addCoin(const Coin &coin);

    int rowCount(const QModelIndex &parent = QModelIndex()) const;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;

//signals:
//    void dataChanged();

protected:
    QHash<int,QByteArray> roleNames() const;

private:
    QList<Coin> mCoins;
};

#endif // MYLISTMODEL_H
