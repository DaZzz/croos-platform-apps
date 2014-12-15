#ifndef EDITABLEFILESYSTEMMODEL_H
#define EDITABLEFILESYSTEMMODEL_H

#include <QFileSystemModel>
#include <QModelIndex>

class EditableFileSystemModel : public QFileSystemModel
{
    Q_OBJECT
public:
    explicit EditableFileSystemModel(QObject *parent = 0);

    Qt::DropActions supportedDropActions() const;
    Qt::ItemFlags flags(const QModelIndex &index) const;
//    QStringList mimeTypes() const;
//    QMimeData *mimeData(const QModelIndexList &indexes) const;
    bool dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent);


signals:

public slots:

};

#endif // EDITABLEFILESYSTEMMODEL_H
