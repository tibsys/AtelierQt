#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QObject>
#include <QAbstractItemModel>

class TableModel : public QAbstractItemModel
{
public:
    TableModel();

    // QAbstractItemModel interface
public:
    QModelIndex index(int row, int column, const QModelIndex &parent) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent) const;
    int columnCount(const QModelIndex &parent) const;
    QVariant data(const QModelIndex &index, int role) const;
};

#endif // TABLEMODEL_H
