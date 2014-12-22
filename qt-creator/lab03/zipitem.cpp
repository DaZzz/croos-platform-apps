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

ZipItem *ZipItem::child(int row)
{
    return childItems.value(row);
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

QString ZipItem::setName(const QString &name)
{
    this->name = name;
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

bool ZipItem::insertChildren(int position, int count, int columns)
{
//    if (position < 0 || position > childItems.size())
//        return false;

//    for (int row = 0; row < count; ++row) {
//        QVariant data(columns);
//        ZipItem *item = new ZipItem(data, this);
//        childItems.insert(position, item);
//    }

//    return true;
}

bool ZipItem::insertColumns(int position, int columns)
{
//    if (position < 0 || position > itemData.size())
//        return false;

//    for (int column = 0; column < columns; ++column)
//        itemData.insert(position, QVariant());

//    foreach (ZipItem *child, childItems)
//        child->insertColumns(position, columns);

//    return true;
}

bool ZipItem::removeChildren(int position, int count)
{
    if (position < 0 || position + count > childItems.size())
        return false;

    for (int row = 0; row < count; ++row)
        delete childItems.takeAt(position);

    return true;
}

bool ZipItem::removeColumns(int position, int columns)
{
//    if (position < 0 || position + columns > itemData.size())
//        return false;

//    for (int column = 0; column < columns; ++column)
//        itemData.remove(position);

//    foreach (ZipItem *child, childItems)
//        child->removeColumns(position, columns);

//    return true;
}

int ZipItem::childNumber() const
{
    if (parentItem)
        return parentItem->childItems.indexOf(const_cast<ZipItem*>(this));

    return 0;
}
