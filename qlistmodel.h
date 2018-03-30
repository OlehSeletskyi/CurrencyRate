#ifndef QLISTMODEL_H
#define QLISTMODEL_H

#include <QAbstractListModel>
#include <QStringList>

//#include <QObject>
//#include <QQmlListProperty>

class QListModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles {
        NameRole = Qt::UserRole + 1,
        ShortNameRole,
        RateRole
    };

    QListModel(QObject *parent = nullptr);

    virtual int rowCount(const QModelIndex &parent) const;

    virtual QVariant data(const QModelIndex &index, int role) const;

    virtual QHash<int,QByteArray> roleNames() const;

    Q_INVOKABLE void add();

//    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole);
//    Qt::ItemFlags flags(const QModelIndex & index) const;

private:
    QStringList mData;
};

#endif // QLISTMODEL_H
