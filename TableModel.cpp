#include "TableModel.h"

TableModel::TableModel(QObject* parent) : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex& /*parent*/) const
{
   return 2;
}

int TableModel::columnCount(const QModelIndex& /*parent*/) const
{
    return 3;
}


QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
       return QString("R%1, C%2")
                   .arg(index.row() + 1)
                   .arg(index.column() +1);
    }

    return QVariant();
}
