#include "mylistmodel.h"
#include "coin.h"

MyListModel::MyListModel(QObject *parent) : QAbstractListModel(parent)
{
}

void MyListModel::addCoin(const Coin &coin)
{
    beginInsertRows(QModelIndex(), rowCount(), rowCount());
    mCoins << coin;
    endInsertRows();
}

int MyListModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mCoins.count();
}

QVariant MyListModel::data(const QModelIndex &index, int role) const
{
    if(index.row() < 0 || index.row() >= mCoins.count())
    {
        return QVariant();
    }
    const Coin &coin = mCoins[index.row()];

    switch (role) {
    case NameRole:
        return coin.name();
    case ShortNameRole:
        return coin.shortName();
    case RateRole:
        return coin.rate();

    default:
        return QVariant();
    }
}

QHash<int, QByteArray> MyListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ShortNameRole] = "shortName";
    roles[RateRole] = "rate";

    return roles;
}
