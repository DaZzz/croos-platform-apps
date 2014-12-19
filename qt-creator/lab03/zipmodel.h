#ifndef ZIPMODEL_H
#define ZIPMODEL_H

#include <QAbstractItemModel>
#include "zipitem.h"

class ZipModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ZipModel(const QString &filePath, Object *parent = 0);
    ~ZipModel();

    QVariant data(const QModelIndex &index, int role) const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

private:
    ZipItem *rootItem;
};

#endif // ZIPMODEL_H
