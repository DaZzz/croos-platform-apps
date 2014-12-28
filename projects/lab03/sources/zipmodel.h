#ifndef ZIPMODEL_H
#define ZIPMODEL_H

#include <QAbstractItemModel>
#include "zipitem.h"

class ZipModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    ZipModel(const QString &filePath, QObject *parent = 0);
    ~ZipModel();

    QVariant data(const QModelIndex &index, int role) const;
    bool setData(const QModelIndex &idx, const QVariant &value, int role);
    Qt::ItemFlags flags(const QModelIndex &index) const;
    QVariant headerData(int section, Qt::Orientation orientation, int role=Qt::DisplayRole) const;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const;
    QModelIndex parent(const QModelIndex &child) const;
    int rowCount(const QModelIndex &parent = QModelIndex()) const;
    int columnCount(const QModelIndex &parent = QModelIndex()) const;

    // Для редактирования
    bool insertColumns(int position, int columns,
                           const QModelIndex &parent = QModelIndex());
    bool removeColumns(int position, int columns,
                       const QModelIndex &parent = QModelIndex());
    bool insertRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex());
    bool removeRows(int position, int rows,
                    const QModelIndex &parent = QModelIndex());

private:
    ZipItem *rootItem;
    ZipItem *getItem(const QModelIndex &index) const;
};

#endif // ZIPMODEL_H
