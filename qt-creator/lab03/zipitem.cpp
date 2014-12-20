#include "zipitem.h"

ZipItem::ZipItem(const QString &name, int size, bool isDirectory, ZipItem *parent):
    name(name), size(size), isDirectory(isDirectory)
{
    parentItem = parent;
}

ZipItem::~ZipItem()
{
    qDeleteAll(childItems);
}

void ZipItem::appendChild(ZipItem *item)
{
    childItems.append(item);
}

ZipItem *ZipItem::parent()
{
    return parentItem;
}

int ZipItem::childCount() const
{
    return childItems.count();
}

int ZipItem::columnCount() const
{
    // Размер и имя
    return 2;
}

int ZipItem::row() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<ZipItem*>(this));
    return 0;
}

int ZipItem::getSize() const
{

    if (isDirectory) {
        int size = 0;
        for (ZipItem* zi : childItems)
            size += zi->getSize();
        return size;
    }
    else
        return this->size;
}

bool ZipItem::isDir() const
{
    return isDirectory;
}

QString ZipItem::getName() const
{
    return name;
}

QVariant ZipItem::data(int column) const
{
    switch (column) {
        case 0:
            return name;
            break;
        case 1:
            return size;
            break;
        default:
            return QVariant();
            break;
    }
}



