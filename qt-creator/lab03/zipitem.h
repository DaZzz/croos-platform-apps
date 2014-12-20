#ifndef ZIPITEM_H
#define ZIPITEM_H

#include <QString>
#include <QList>
#include <QVariant>

class ZipItem
{
public:
    ZipItem(const QString &name, int size, bool isDirectory, ZipItem *parent = 0);
    ~ZipItem();

    void appendChild(ZipItem *item);

    ZipItem *child(int row);
    ZipItem *parent();
    int childCount() const;
    int columnCount() const;
    int row() const;
    int getSize() const;
    bool isDir() const;
    QString getName() const;
    QVariant data(int column) const;


private:
    int size;
    bool isDirectory;
    QString name;
    ZipItem *parentItem;
    QList<ZipItem *> childItems;
};

#endif // ZIPITEM_H
