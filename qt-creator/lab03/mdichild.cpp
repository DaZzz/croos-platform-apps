#include "mdichild.h"
#include <QFileSystemModel>
#include <QVBoxLayout>
#include "editablefilesystemmodel.h"
#include <QTreeView>

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

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(treeView);
    setLayout(mainLayout);
}

void MdiChild::loadFile(QString filePath)
{
     model->setRootPath(filePath);
     treeView->setRootIndex(model->index(filePath));
}
