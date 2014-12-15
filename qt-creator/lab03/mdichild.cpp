#include "mdichild.h"
#include <QFileSystemModel>
#include <QVBoxLayout>
#include "editablefilesystemmodel.h"
#include <QTreeView>
#include <QMenu>
#include <QDebug>
#include <QSignalMapper>
#include <QAction>
#include <QFileDialog>

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

MdiChild::MdiChild(QWidget *parent) :
    QWidget(parent)
{

    model = new EditableFileSystemModel;
    model->setReadOnly(false);

    treeView = new QTreeView();
    treeView->setModel(model);
    treeView->setSelectionMode(QAbstractItemView::ExtendedSelection);
    treeView->setDragEnabled(true);
    treeView->setAcceptDrops(true);
    treeView->setDropIndicatorShown(true);
    treeView->setColumnWidth(0, 200);

    treeView->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(treeView, SIGNAL(customContextMenuRequested(const QPoint &)), this, SLOT(onCustomContextMenu(const QPoint &)));

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(treeView);
    setLayout(mainLayout);

    createActions();
}

void MdiChild::loadFile(QString filePath)
{
     model->setRootPath(filePath);
     treeView->setRootIndex(model->index(filePath));
}

void MdiChild::onCustomContextMenu(const QPoint &point)
{
    QModelIndex index = treeView->indexAt(point);
    QMenu *contextMenu = new QMenu("&Контекстное меню");

    contextMenu->addAction(createDirAction);
    contextMenu->addAction(addDirAction);
    contextMenu->addAction(addFileAction);
    contextMenu->addSeparator();
    contextMenu->addAction(removeAction);

    if (index.isValid()) {
        QAction *action = contextMenu->exec(treeView->mapToGlobal(point));
    }
}

void MdiChild::createActions()
{
    removeAction = new QAction("&Удалить", this);
    connect(removeAction, SIGNAL(triggered()), this, SLOT(remove()));
    createDirAction = new QAction("&Создать каталог", this);
    connect(createDirAction, SIGNAL(triggered()), this, SLOT(createDir()));
    addDirAction = new QAction("&Добавить существующий каталог", this);
    connect(addDirAction, SIGNAL(triggered()), this, SLOT(addDir()));
    addFileAction = new QAction("&Добавить файл", this);
    connect(addFileAction, SIGNAL(triggered()), this, SLOT(addFile()));
}

void MdiChild::remove()
{
    QModelIndexList list = treeView->selectionModel()->selectedRows();
    for (QModelIndex index : list) {
        model->remove(index);
    }
}

void MdiChild::createDir()
{
    QModelIndexList list = treeView->selectionModel()->selectedRows();

    if (list.length() != 1) {
        return;
    }

    auto index = list.first();

    if (model->fileInfo(index).isDir()) {
        auto defaultName = QString("Новая папка");
        auto fullPath = model->fileInfo(index).filePath() + QDir::separator() + defaultName;
        if (!QFileInfo::exists(fullPath)) {
            model->mkdir(index, defaultName);
        }
        else {
            int i = 1;
            auto str = QString("%1 %2").arg(fullPath);
            while (QFileInfo::exists(str.arg(i))) {
                ++i;
            }
            model->mkdir(index, QString("%1 %2").arg(defaultName).arg(i));
        }
    }
}

void MdiChild::addDir()
{
    QModelIndexList list = treeView->selectionModel()->selectedRows();

    if (list.length() != 1) {
        return;
    }

    auto index = list.first();

    if (model->fileInfo(index).isDir()) {
        QString path = QFileDialog::getExistingDirectory(
                            this, tr("Добавить каталог"),
                            QDir::rootPath(),
                            QFileDialog::ShowDirsOnly
                            | QFileDialog::DontResolveSymlinks);

        QString to = model->filePath(index) + QDir::separator();
        cpDir(path, to + QFileInfo(path).fileName());
    }


}

void MdiChild::addFile()
{
    QModelIndexList list = treeView->selectionModel()->selectedRows();

    if (list.length() != 1) {
        return;
    }

    auto index = list.first();

    if (model->fileInfo(index).isDir()) {
        QString path = QFileDialog::getOpenFileName(
                            this, tr("Добавить файл"),
                            QDir::rootPath(),
                            tr("Файловый архив (*.*)"));

        QString to = model->filePath(index) + QDir::separator();
        QFile::copy(path, to + QFileInfo(path).fileName());
    }
}

