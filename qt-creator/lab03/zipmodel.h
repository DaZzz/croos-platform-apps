#ifndef ZIPMODEL_H
#define ZIPMODEL_H

#include <QAbstractItemModel>

class ZipModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit ZipModel(QObject *parent = 0);

private:



signals:

public slots:

};

#endif // ZIPMODEL_H
