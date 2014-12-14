#ifndef MDICHILD_H
#define MDICHILD_H

#include <QWidget>
//#include "treeview.h"
#include <QTreeView>
#include "editablefilesystemmodel.h"

class MdiChild : public QWidget
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);
    void loadFile(QString filePath);

private:
    EditableFileSystemModel *model;
    QTreeView *treeView;

signals:

public slots:

};

#endif // MDICHILD_H
