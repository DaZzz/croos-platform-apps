#include "editablefilesystemmodel.h"
#include <QtWidgets>

EditableFileSystemModel::EditableFileSystemModel(QObject *parent) :
    QFileSystemModel(parent)
{
}

Qt::DropActions EditableFileSystemModel::supportedDropActions() const
{
    return Qt::CopyAction | Qt::MoveAction;
}

Qt::ItemFlags EditableFileSystemModel::flags(const QModelIndex &index) const
{
    auto defaultFlags = QFileSystemModel::flags(index);

    if (index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | defaultFlags;
    else
        return Qt::ItemIsDropEnabled | defaultFlags;
}

//QStringList EditableFileSystemModel::mimeTypes() const
//{
//    QStringList types;
//    types << "application/vnd.text.list";
//    return types;
//}

//QMimeData *EditableFileSystemModel::mimeData(const QModelIndexList &indexes) const
//{
//    QMimeData *mimeData = new QMimeData();
//    QByteArray encodedData;

//    QDataStream stream(&encodedData, QIODevice::WriteOnly);

//    foreach (const QModelIndex &index, indexes) {
//        if (index.isValid()) {
//            QString text = data(index, Qt::DisplayRole).toString();
//            stream << text;
//        }
//    }

//    mimeData->setData("application/vnd.text.list", encodedData);
//    return mimeData;
//}

static bool rmDir(const QString &dirPath)
{
    QDir dir(dirPath);
    if (!dir.exists())
        return true;
    foreach(const QFileInfo &info, dir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
        if (info.isDir()) {
            if (!rmDir(info.filePath()))
                return false;
        } else {
            if (!dir.remove(info.fileName()))
                return false;
        }
    }
    QDir parentDir(QFileInfo(dirPath).path());
    return parentDir.rmdir(QFileInfo(dirPath).fileName());
}

static bool cpDir(const QString &srcPath, const QString &dstPath)
{
    rmDir(dstPath);
    QDir parentDstDir(QFileInfo(dstPath).path());
    if (!parentDstDir.mkdir(QFileInfo(dstPath).fileName()))
        return false;

    QDir srcDir(srcPath);
    foreach(const QFileInfo &info, srcDir.entryInfoList(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot)) {
        QString srcItemPath = srcPath + "/" + info.fileName();
        QString dstItemPath = dstPath + "/" + info.fileName();
        if (info.isDir()) {
            if (!cpDir(srcItemPath, dstItemPath)) {
                return false;
            }
        } else if (info.isFile()) {
            if (!QFile::copy(srcItemPath, dstItemPath)) {
                return false;
            }
        } else {
            qDebug() << "Unhandled item" << info.filePath() << "in cpDir";
        }
    }
    return true;
}

bool EditableFileSystemModel::dropMimeData(const QMimeData *data,
     Qt::DropAction action, int row, int column, const QModelIndex &parent)
{
    Q_UNUSED(row);
    Q_UNUSED(column);

    if (!parent.isValid() || isReadOnly())
        return false;

    bool success = true;
    QString to = filePath(parent) + QDir::separator();

    QList<QUrl> urls = data->urls();
    QList<QUrl>::const_iterator it = urls.constBegin();

    switch (action) {
    case Qt::CopyAction:
        for (; it != urls.constEnd(); ++it) {
            QString path = (*it).toLocalFile();
            if (QFileInfo(path).isDir())
                success = cpDir(path, to + QFileInfo(path).fileName()) && success;
            else
                success = QFile::copy(path, to + QFileInfo(path).fileName()) && success;
        }
        break;
    case Qt::LinkAction:
        for (; it != urls.constEnd(); ++it) {
            QString path = (*it).toLocalFile();
            success = QFile::link(path, to + QFileInfo(path).fileName()) && success;
        }
        break;
    case Qt::MoveAction:
        for (; it != urls.constEnd(); ++it) {
            QString path = (*it).toLocalFile();
            success = QFile::copy(path, to + QFileInfo(path).fileName())
                      && QFile::remove(path) && success;
        }
        break;
    default:
        return false;
    }

    return success;

}
