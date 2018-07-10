#include "TableModel.h"

#include <algorithm>

TableModelItem::TableModelItem(QString text) : m_text(text)
{

}

QString TableModelItem::text() const
{
    return m_text;
}

TableModel::TableModel(QObject* parent) : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex& /*parent*/) const
{
   return m_items.size();
}

int TableModel::columnCount(const QModelIndex& /*parent*/) const
{
    return 1;
}


QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (role == Qt::DisplayRole)
    {
        return m_items[index.row()].text();
    }

    return QVariant();
}

void TableModel::appendItem(TableModelItem item)
{
    const int row = m_items.size();
    beginInsertRows(QModelIndex(), row, row);
    m_items.push_back(item);
    endInsertRows();
}

void TableModel::sortByColumn(int /*column*/, Qt::SortOrder order)
{
    if (order == Qt::AscendingOrder)
    {
        std::sort(m_items.begin( ), m_items.end(),[](const TableModelItem& lhs, const TableModelItem& rhs)
        {
            return lhs.text() < rhs.text();
        });
    }
    else
    {
        std::sort(m_items.begin( ), m_items.end(),[](const TableModelItem& lhs, const TableModelItem& rhs)
        {
            return lhs.text() > rhs.text();
        });
    }

    emit layoutChanged();
}