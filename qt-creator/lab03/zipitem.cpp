#include "zipitem.h"

ZipItem::ZipItem(TreeItem *parent, QString &name, int size, bool isDir):
    name(name), size(size), isDir(isDir)
{
    parentItem = parent;
}

ZipItem::~ZipItem()
{
    qDeleteAll(childItems);
}

ZipItem *ZipItem::appendChild(ZipItem *item)
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

    if (isDir) {
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
    return isDir;
}

QString ZipItem::getName() const
{
    return name;
}



