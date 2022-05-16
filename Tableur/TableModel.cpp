#include "TableModel.h"
#include <QDebug>
#include <QFont>

TableModel::TableModel()
{

}


QModelIndex TableModel::index(int row, int column, const QModelIndex &parent) const
{
    return createIndex(row, column);
}

QModelIndex TableModel::parent(const QModelIndex &child) const
{
    return QModelIndex();
}

int TableModel::rowCount(const QModelIndex &parent) const
{
    qDebug() << "rowCount appelé";
    return 100;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
    qDebug() << "columnCount appelé";
    return 4;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    qDebug() << "data appelé : " << index << ", role : " << role;

    switch(role) {
    case Qt::DisplayRole: return "toto";
    case Qt::FontRole: return QFont("Helvetica", 12);
    case Qt::ToolTipRole: return "tooltip";
    case Qt::TextAlignmentRole: return Qt::AlignRight;
    }

    return QVariant();
}
