#ifndef MDICHILD_H
#define MDICHILD_H

#include <QWidget>
#include <QFileSystemModel>
#include <QTreeView>

class MdiChild : public QWidget
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);
    void loadFile(QString filePath);

private:
    QFileSystemModel *model;
    QTreeView *treeView;

signals:

public slots:

};

#endif // MDICHILD_H
