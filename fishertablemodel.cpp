#include "fishertablemodel.h"

#include <QDebug>

FisherTableModel::FisherTableModel(QObject* pobj):
    QAbstractTableModel(pobj)
{
    // Making horizontal header
    for (int i = 0; i < _data.columnCount(); i++)
        if (i == _data.columnCount()-1)
            horHeaderData << QString::number(_data.columnCount()+1);
        else
            horHeaderData << QString::number(i+1);

    // Making vertical header
    for (int i = 0; i < _data.rowCount(); i++)
        verHeaderData << QString::number(i+1);
}

int FisherTableModel::rowCount(const QModelIndex &parent) const {
    //qDebug() << _data.rowCount();
     return _data.rowCount();
}

int FisherTableModel::columnCount(const QModelIndex &parent) const {
    //qDebug() << "coluumn:" << _data.columnCount();
     return _data.columnCount();
}

QVariant FisherTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();
    else if (role == Qt::DisplayRole || role == Qt::EditRole) {
        //qDebug() << "here";
        return QString::number(_data.get(index.column()+1, index.row()+1));
    } else {
        return QVariant();
    }
}

QVariant FisherTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        return horHeaderData[section];
    }
    if (orientation == Qt::Vertical && role == Qt::DisplayRole) {
        return verHeaderData[section];
    }
    return QVariant();
}

