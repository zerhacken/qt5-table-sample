#include "TableModel.h"

TableModel::TableModel(QObject* parent) : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return m_samples.size();
}

int TableModel::columnCount(const QModelIndex& parent) const
{
    Q_UNUSED(parent);
    return 2;
}


QVariant TableModel::data(const QModelIndex& index, int role) const
{
    if (!index.isValid())
    {
        return QVariant();
    }

    if (index.row() >= m_samples.size() || index.row() < 0)
    {
        return QVariant();
    }

    if (role == Qt::DisplayRole)
    {
        // return QString("R%1, C%2").arg(index.row() + 1).arg(index.column() +1);
        const Sample& sample = m_samples.at(index.row());
        if (index.column() == 0) {
            return sample.type;
        } else if (index.column() == 1) {
            return sample.age;
        }
    }

    return QVariant();
}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();

    if (orientation == Qt::Horizontal) {
        switch (section) {
            case 0:
                return tr("type");
            case 1:
                return tr("age");
            default:
                return QVariant();
        }
    }
    return QVariant();
}

bool TableModel::insertRows(int position, int rows, const QModelIndex& index)
{
    Q_UNUSED(index);
    beginInsertRows(QModelIndex(), position, position + rows - 1);
    for (int row = 0; row < rows; ++row)
    {
        m_samples.insert(position, { "invalid", -1 });
    }
    endInsertRows();
    return true;
}

