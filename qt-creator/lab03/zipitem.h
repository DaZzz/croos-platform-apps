#ifndef ZIPITEM_H
#define ZIPITEM_H

#include <QObject>

class ZipItem : public QObject
{
    Q_OBJECT
public:
    explicit ZipItem(QObject *parent = 0);

    ZipItem *child(int row);
    ZipItem *parent();
    int childCount() const;
    int columnCount() const;
    int row() const;
    QString *getSize();
    QString *getName();


private:
    int size;
    QString name;
    ZipItem *parentItem;
    QList<ZipItem *> childItems;
};

#endif // ZIPITEM_H
