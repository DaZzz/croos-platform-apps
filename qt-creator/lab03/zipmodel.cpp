#include "zipmodel.h"

#include <archive.h>
#include <archive_entry.h>
#include <QDebug>
#include <QMap>
#include <QDir>
#include <QFileIconProvider>

ZipModel::ZipModel(const QString &filePath, QObject *parent) :
    QAbstractItemModel(parent)
{
    rootItem = new ZipItem(tr("Корень"), 0, true);

    struct archive *a;
    struct archive_entry *entry;
    int r;
    const char *filePathString = filePath.toStdString().c_str();

    a = archive_read_new();
    archive_read_support_filter_all(a);
    archive_read_support_format_all(a);
    r = archive_read_open_filename(a, filePath.toStdString().c_str(), 10240);

    if (r != ARCHIVE_OK)
        qDebug() << "Archive is not ok!";

    QMap<QString, ZipItem *> pathsMap;

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
      bool isDir           = (archive_entry_filetype(entry) == S_IFDIR);
      QString path         = QString::fromLocal8Bit(archive_entry_pathname(entry));
      int size             = archive_entry_size(entry);

      // удаляем последнйи слэш
      if (isDir) { path.chop(1);}

      QStringList pathList = path.split(QDir::separator());
      QString fileName = pathList.takeLast().replace(":", QDir::separator());
      ZipItem * item;
      ZipItem * parent = pathsMap[pathList.join(QDir::separator())];

      if (parent) {
        item = new ZipItem(fileName, size, isDir, parent);
        parent->appendChild(item);
      }
      else {
        item = new ZipItem(fileName, size, isDir, rootItem);
        rootItem->appendChild(item);
      }
      pathsMap.insert(path, item);
      archive_read_data_skip(a);
    }
}

void setupModel(QStringList files)
{

}

ZipModel::~ZipModel()
{
    delete rootItem;
}

QModelIndex ZipModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    ZipItem *parentItem;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<ZipItem *>(parent.internalPointer());

    ZipItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    else
        return QModelIndex();
}

QModelIndex ZipModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        QModelIndex();

    ZipItem *childItem = static_cast<ZipItem *>(index.internalPointer());
    ZipItem *parentItem = childItem->parent();

    if (parentItem == rootItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

int ZipModel::rowCount(const QModelIndex &parent) const
{
    ZipItem *parentItem;
    if (parent.column() > 0)
        return 0;

    if (!parent.isValid())
        parentItem = rootItem;
    else
        parentItem = static_cast<ZipItem *>(parent.internalPointer());

    return parentItem->childCount();
}

int ZipModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return static_cast<ZipItem*>(parent.internalPointer())->columnCount();
    else
        return rootItem->columnCount();
}

QVariant ZipModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case Qt::DisplayRole: {
        ZipItem *item = static_cast<ZipItem *>(index.internalPointer());
        return item->data(index.column());
    }
    case Qt::DecorationRole: {
        if (index.column() == 0) {
            ZipItem *item = static_cast<ZipItem *>(index.internalPointer());
            QFileIconProvider *fip = new QFileIconProvider;
            if (item->isDir()) {
                return fip->icon(QFileIconProvider::Folder);
            }
            else {
                return fip->icon(QFileIconProvider::File);
            }
        }

    }
    }

    return QVariant();
}

Qt::ItemFlags ZipModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    Qt::ItemFlags flags =  Qt::ItemIsEnabled | Qt::ItemIsSelectable;

    if (index.column() == 0)
        flags |= Qt::ItemIsEditable;

    return flags;
}

QVariant ZipModel::headerData(int section, Qt::Orientation orientation,
                               int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole)
        switch (section) {
        case 0:
            return tr("Имя");
            break;
        case 1:
            return tr("Размер");
            break;
        default:
            return QVariant();
        }

    return QVariant();
}

bool ZipModel::setData(const QModelIndex &idx, const QVariant &value, int role)
{
    if (!idx.isValid())
        return false;

    ZipItem *zitem = static_cast<ZipItem *>(idx.internalPointer());
    zitem->setName(value.toString());
    return true;
}

bool ZipModel::insertColumns(int position, int columns,
                       const QModelIndex &parent)
{
    bool success;

    beginInsertColumns(parent, position, position + columns - 1);
    success = rootItem->insertColumns(position, columns);
    endInsertColumns();

    return success;
}

bool ZipModel::removeColumns(int position, int columns,
                   const QModelIndex &parent)
{
    bool success;

    beginRemoveColumns(parent, position, position + columns - 1);
    success = rootItem->removeColumns(position, columns);
    endRemoveColumns();

    if (rootItem->columnCount() == 0)
        removeRows(0, rowCount());

    return success;
}

bool ZipModel::insertRows(int position, int rows,
                const QModelIndex &parent)
{
    ZipItem *parentItem = getItem(parent);
    bool success;

    beginInsertRows(parent, position, position + rows - 1);
    success = parentItem->insertChildren(position, rows, rootItem->columnCount());
    endInsertRows();

    return success;
}

bool ZipModel::removeRows(int position, int rows,
                const QModelIndex &parent)
{
    ZipItem *parentItem = getItem(parent);
    bool success = true;

    beginRemoveRows(parent, position, position + rows - 1);
    success = parentItem->removeChildren(position, rows);
    endRemoveRows();

    return success;
}

ZipItem *ZipModel::getItem(const QModelIndex &index) const
{
    if (index.isValid()) {
         ZipItem *item = static_cast<ZipItem*>(index.internalPointer());
         if (item) return item;
     }
     return rootItem;
}
