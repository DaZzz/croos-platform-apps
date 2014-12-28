#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{

    Q_OBJECT

private:
    QPixmap pixmap;
    QImage image;

    void drawImage();

public:
    explicit Canvas(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);

public slots:
    void setNewImage(QString &filePath);
    void applySchar();

};

#endif // CANVAS_H
