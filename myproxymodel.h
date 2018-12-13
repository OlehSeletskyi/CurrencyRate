#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>

class MyListModel;

class MyProxyModel : public QSortFilterProxyModel
{

    Q_OBJECT
public:
    explicit MyProxyModel(MyListModel *model = nullptr);
    virtual ~MyProxyModel();

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

};

#endif // MYPROXYMODEL_H
