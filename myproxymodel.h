#ifndef MYPROXYMODEL_H
#define MYPROXYMODEL_H

#include <QSortFilterProxyModel>

class MyListModel;

class MyProxyModel : public QSortFilterProxyModel
{

    Q_OBJECT
public:
    MyProxyModel(MyListModel *model);
    virtual ~MyProxyModel();

    bool filterAcceptsRow(int source_row, const QModelIndex &source_parent) const override;

};

#endif // MYPROXYMODEL_H
