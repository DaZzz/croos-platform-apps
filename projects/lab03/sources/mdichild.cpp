#include <QFileSystemModel>
#include <QVBoxLayout>
#include <QTreeView>
#include <QMenu>
#include <QDebug>
#include <QSignalMapper>
#include <QAction>
#include <QFileDialog>

#include "mdichild.h"
#include "zipmodel.h"

MdiChild::MdiChild(QString &filePath, QWidget *parent) :
    QWidget(parent)
{
    model = new ZipModel(filePath);

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


void MdiChild::onCustomContextMenu(const QPoint &point)
{
    QModelIndex index = treeView->indexAt(point);
    QMenu *contextMenu = new QMenu(tr("&Контекстное меню"));

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
    removeAction = new QAction(tr("&Удалить"), this);
    connect(removeAction, SIGNAL(triggered()), this, SLOT(remove()));
    createDirAction = new QAction(tr("&Создать каталог"), this);
    connect(createDirAction, SIGNAL(triggered()), this, SLOT(createDir()));
    addDirAction = new QAction(tr("&Добавить существующий каталог"), this);
    connect(addDirAction, SIGNAL(triggered()), this, SLOT(addDir()));
    addFileAction = new QAction(tr("&Добавить файл"), this);
    connect(addFileAction, SIGNAL(triggered()), this, SLOT(addFile()));
}

void MdiChild::remove()
{

}

void MdiChild::createDir()
{

}

void MdiChild::addDir()
{

}

void MdiChild::addFile()
{

}
