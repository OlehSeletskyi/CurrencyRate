#include "mylistmodel.h"
#include "coin.h"
#include <QDebug>

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
    if(!index.isValid() || index.row() < 0 || index.row() >= mCoins.count())
    {
        return QVariant();
    }
    const Coin &coin = mCoins.at(index.row());

    switch (role) {
    case NameRole:
        return coin.name();
    case ShortNameRole:
        return coin.shortName();
    case RateRole:
        return coin.rate();
    case RateDifferenceRole:
        return coin.rateDifference();

    default:
        return QVariant();
    }
}

Coin MyListModel::getCoin(int element)
{
    return mCoins.at(element);
}

void MyListModel::clearModel()
{
    beginResetModel();
    mCoins.clear();
    endResetModel();
}

QHash<int, QByteArray> MyListModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[NameRole] = "name";
    roles[ShortNameRole] = "shortName";
    roles[RateRole] = "rate";
    roles[RateDifferenceRole] = "rateDifference";

    return roles;
}
