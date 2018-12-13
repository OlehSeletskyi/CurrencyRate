#include "myproxymodel.h"
#include "mylistmodel.h"

MyProxyModel::MyProxyModel(MyListModel* model)
{
    setSourceModel(model);
}

MyProxyModel::~MyProxyModel()
{
}

bool MyProxyModel::filterAcceptsRow(int source_row, const QModelIndex &source_parent) const
{
    bool ret(false);
    if(this->sourceModel() != nullptr)
    {
        auto index = this->sourceModel()->index(source_row, 0, source_parent);
        if(index.isValid())
        {
            auto valueNameRole = index.data(MyListModel::Roles::NameRole);
            auto valueShortNameRole = index.data(MyListModel::Roles::ShortNameRole);
            QString findText = filterRegExp().pattern();
            findText = findText.toLower();
            QString nameRole = valueNameRole.toString();
            nameRole = nameRole.toLower();
            QString shortNameRole = valueShortNameRole.toString();
            shortNameRole = shortNameRole.toLower();
            if(valueNameRole.isValid() || valueShortNameRole.isValid())
            {
               if(nameRole.indexOf(findText) >= 0 || shortNameRole.indexOf(findText) >= 0)
               {
                   ret = true;
               }
            }
        }
    }
    return ret;
}
