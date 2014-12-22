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
    QString setName(const QString &name);
    QVariant data(int column) const;
    bool insertChildren(int position, int count, int columns);
    bool insertColumns(int position, int columns);
    bool removeChildren(int position, int count);
    bool removeColumns(int position, int columns);
    int childNumber() const;
//    bool setData(int column, const QVariant &value);


private:
    int size;
    bool isDirectory;
    QString name;
    ZipItem *parentItem;
    QList<ZipItem *> childItems;
};

#endif // ZIPITEM_H
