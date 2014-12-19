#ifndef ZIPITEM_H
#define ZIPITEM_H

class ZipItem
{
public:
    ZipItem(TreeItem *parent, QString &name, int size, bool isDir);
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


private:
    int size;
    bool isDir;
    QString name;
    ZipItem *parentItem;
    QList<ZipItem *> childItems;
};

#endif // ZIPITEM_H
