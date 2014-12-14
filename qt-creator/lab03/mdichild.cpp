#include "mdichild.h"
#include <QFileSystemModel>
#include <QTreeView>
#include <QVBoxLayout>

MdiChild::MdiChild(QWidget *parent) :
    QWidget(parent)
{

    model = new QFileSystemModel;

    treeView = new QTreeView();
    treeView->setModel(model);

    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addWidget(treeView);
    setLayout(mainLayout);
}

void MdiChild::loadFile(QString filePath)
{
     model->setRootPath(filePath);
}
