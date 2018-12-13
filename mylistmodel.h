#ifndef MYLISTMODEL_H
#define MYLISTMODEL_H

#include <QAbstractListModel>
//#include <QStringList>
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
    Q_ENUM(Roles)

    MyListModel(QObject *parent = nullptr);

    void addCoin(const Coin &coin);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    Q_INVOKABLE void clearModel();

protected:
    QHash<int,QByteArray> roleNames() const override;

private:
    QList<Coin> mCoins;
};

#endif // MYLISTMODEL_H
