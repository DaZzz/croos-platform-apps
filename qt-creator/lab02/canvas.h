#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>

class Canvas : public QWidget
{
    Q_OBJECT

private:
    QPixmap pixmap;
    void drawGraph(QPainter &painter, int n);
    std::vector<QPoint> getPoints(int n);

public:
    explicit Canvas(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);

};

#endif // CANVAS_H
