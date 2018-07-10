#pragma once

#include <QAbstractItemModel>
#include <vector>

class TableModelItem
{
public:
    TableModelItem(QString text);
    QString text() const;
private:
    QString m_text;
};

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject* parent);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    void appendItem(TableModelItem item);
public slots:
    void sortByColumn(int column, Qt::SortOrder order);
private:
    std::vector<TableModelItem> m_items;
};
