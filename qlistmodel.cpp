#include "qlistmodel.h"

QListModel::QListModel(QObject *parent) : QAbstractListModel(parent)
{
    mData.append("old");
    mData.append("another_old");
}

int QListModel::rowCount(const QModelIndex &parent) const
{
    if(parent.isValid())
    {
        return 0;
    }
    return mData.size();
}

QVariant QListModel::data(const QModelIndex &index, int role) const
{
    if(!index.isValid())
    {
        return QVariant();
    }
    switch (role) {
    case NameRole:
        return mData.at(index.row());
    case ShortNameRole:
        return mData.at(index.row());
    case RateRole:
        return mData.at(index.row());

    default:
        return QVariant();
    }
}

QHash<int, QByteArray> QListModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[NameRole] = "name";
    roles[ShortNameRole] = "shortName";
    roles[RateRole] = "rate";

    return roles;
}

void QListModel::add()
{
    beginInsertRows(QModelIndex(), mData.size(), mData.size());
    mData.append("new");
    endInsertRows();

    mData[0] = QString("Size: %1").arg(mData.size());
    QModelIndex index = createIndex(0, 0, static_cast<void *>(0));
    emit dataChanged(index, index);


}
//bool QListModel::setData(const QModelIndex &index, const QVariant &value, int role)
//{
//    if(role == Qt::EditRole)
//    {
//        list.replace(index.row(), value.toInt());
//    }
//}

//Qt::ItemFlag QListModel::flags(const QModelIndex &index) const
//{
//    if(!index.isValid())
//    {
//        return Qt::NoItemFlags;
//    }
//    return Qt::ItemIsEnabled | Qt::ItemIsSelectable | Qt::ItemIsEditable;
//}
