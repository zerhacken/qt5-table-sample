#pragma once

#include <QAbstractItemModel>
#include <QList>

struct Sample
{
    QString type;
    int age;
    bool operator==(const Sample& rhs) const
    {
        return type == rhs.type && age == rhs.age;
    }
};

inline QDataStream& operator<<(QDataStream &stream, const Sample& sample)
{
    return stream << sample.type << sample.age;
}

inline QDataStream& operator>>(QDataStream &stream, Sample& sample)
{
    return stream >> sample.type >> sample.age;
}

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    TableModel(QObject* parent);
    int rowCount(const QModelIndex& parent = QModelIndex()) const override ;
    int columnCount(const QModelIndex& parent = QModelIndex()) const override;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const override;
    bool insertRows(int position, int rows, const QModelIndex& index = QModelIndex()) override;
private:
    QList<Sample> m_samples;
};
