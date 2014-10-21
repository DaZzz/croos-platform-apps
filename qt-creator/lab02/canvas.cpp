#include "canvas.h"
#include <QtWidgets>
#include <cmath>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    _pointsNumber = 1;
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    pixmap = QPixmap(event->size());
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    drawGraph(painter, _pointsNumber);
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap);
}

void Canvas::drawGraph(QPainter &painter, int n)
{
    const int R = 10;
    std::vector<QPoint> points = getPoints(n);

    painter.setPen(QColor("#bbbbbb"));
    for (int i = 0; i < points.size(); ++i) {
        for (int j = i; j < points.size(); ++j) {
            painter.drawLine(points[i], points[j]);
        }
    }

    painter.setBrush(QBrush(QColor("#97e9b1")));
    painter.setPen(Qt::transparent);
    for (int i = 0; i < points.size(); ++i) {
        painter.drawEllipse(points[i].rx() - R, points[i].ry() - R, 2*R, 2*R);
    }
}

std::vector<QPoint> Canvas::getPoints(int n)
{
    const double STEP = 2 * M_PI / n;
    std::vector<QPoint> v;

    for (double t = 0; t < 2 * M_PI; t += STEP) {
        int x = static_cast<int>(150 * cos(t) + geometry().center().rx());
        int y = static_cast<int>(150 * sin(t) + geometry().center().ry());
        v.push_back(QPoint(x, y));
    }

    return v;
}

void Canvas::setPointsNumber(int newValue)
{
    _pointsNumber = newValue;
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);
    drawGraph(painter, _pointsNumber);
}
