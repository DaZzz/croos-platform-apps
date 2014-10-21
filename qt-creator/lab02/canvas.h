#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <vector>

class Canvas : public QWidget
{
    Q_OBJECT

private:
    QPixmap pixmap;
    int _pointsNumber;

    void drawGraph(QPainter &painter, int n);
    std::vector<QPoint> getPoints(int n);

public:
    explicit Canvas(QWidget *parent = 0);

protected:
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *);

public slots:
    void setPointsNumber(int newValue);

};

#endif // CANVAS_H
