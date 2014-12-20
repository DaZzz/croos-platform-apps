#include "zipmodel.h"

//#include <archive.h>
//#include <archive_entry.h>
#include <QDebug>

ZipModel::ZipModel(const QString &filePath, QObject *parent) :
    QAbstractItemModel(parent)
{
    //
//    struct archive *a;
//    struct archive_entry *entry;
//    int r;
//    const char *filePathString = filePath.toStdString().c_str();

//    a = archive_read_new();
//    archive_read_support_filter_all(a);
//    archive_read_support_format_all(a);

//    r = archive_read_open_filename(a, filePathString, 10240);

//    if (r != ARCHIVE_OK)
//        qDebug() << "Archive is not ok!";

//    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
////      qDebug() << archive_entry_pathname(entry);
////      qDebug() << archive_entry_stat(entry)->st_size;
////      qDebug() << (QString::number(S_IFDIR, 8));
////      qDebug() << (QString::number(archive_entry_stat(entry)->st_mode));

//      // Инициализация через массив
//      archive_read_data_skip(a);  // Note 2
//    }

    // Инициализировать статикой
    rootItem = new ZipItem("Корень", 0, true);
    ZipItem *innerDir = new ZipItem("Папка", 0, true, rootItem);
    rootItem->appendChild(innerDir);
    rootItem->appendChild(new ZipItem("Файл", 0, false, rootItem));
    innerDir->appendChild(new ZipItem("Вложенный файл", 0, false, innerDir));

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

    if (role != Qt::DisplayRole)
        return QVariant();

    ZipItem *item = static_cast<ZipItem *>(index.internalPointer());

    return item->data(index.column());
}

Qt::ItemFlags ZipModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return 0;

    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
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
