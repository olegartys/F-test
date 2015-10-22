#ifndef FISHERTABLEMODEL_H
#define FISHERTABLEMODEL_H

#include <QAbstractTableModel>
#include "fishertable.h"


class FisherTableModel: public QAbstractTableModel
{
public:
    FisherTableModel(QObject* pobj = 0);

    int rowCount(const QModelIndex &parent  = QModelIndex()) const;
    int columnCount(const QModelIndex &parent  = QModelIndex()) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    QVariant data(const QModelIndex &index, int role=Qt::DisplayRole) const;

private:
    FisherTable _data;
    QList<QString> horHeaderData, verHeaderData;

};

#endif // FISHERTABLEMODEL_H
