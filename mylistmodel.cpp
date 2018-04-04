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
    case RateDifferenceRole:
        return coin.rateDifference();

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
    roles[RateDifferenceRole] = "rateDifference";

    return roles;
}
// void MyListModel::setTextFind(const QString textFind)
// {
//     qDebug() << "textFind" << textFind;
//     QList<Coin> coinsList;
//     mCoins.clear();
//     if(textFind == "")
//     {
//         mCoins=mFullCoinsList;
//         return;
//     }
//     else
//     {

//         for(int i = 0; i < mFullCoinsList.count(); i++)
//         {
//             QString name = mFullCoinsList.at(i).name();
//             QString shortName = mFullCoinsList.at(i).shortName();
//             qDebug() << "name" << name;
//             qDebug() << "shortName" << shortName;
//             if(name.indexOf(textFind) >= 0 || shortName.indexOf(textFind) >=0)
//             {
//                 mCoins.append(mFullCoinsList.at(i));
//                 qDebug() << "********QLIST" <<mFullCoinsList.at(i).shortName();
//             }
//         }
//     }
//     emit dataChanged();
// }
