#ifndef QLISTMODEL_H
#define QLISTMODEL_H

#include <QObject>
#include <QQmlListProperty>

class Coin;

class QListModel : public QObject

{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<Coin> data READ data NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
public:

    QListModel(QObject *parent = nullptr);

    QQmlListProperty<Coin> data();

    Q_INVOKABLE void add();

signals:

    void dataChanged();

private:

    static void appendData(QQmlListProperty<Coin> *list, Coin *value);
    static int countData(QQmlListProperty<Coin> *list);
    static Coin *atData(QQmlListProperty<Coin> *list, int index);
    static void clearData(QQmlListProperty<Coin> *list);

    QList<Coin*> mData;
};

#endif // QLISTMODEL_H
