#ifndef MDICHILD_H
#define MDICHILD_H

#include <QWidget>
#include <QTreeView>

class MdiChild : public QWidget
{
    Q_OBJECT
public:
    explicit MdiChild(QWidget *parent = 0);

private:
    void createActions();

    QTreeView *treeView;
    QAction *removeAction;
    QAction *addFileAction;
    QAction *addDirAction;
    QAction *createDirAction;

signals:

public slots:
    void onCustomContextMenu(const QPoint &point);
    void remove();
    void addFile();
    void addDir();
    void createDir();

};

#endif // MDICHILD_H
