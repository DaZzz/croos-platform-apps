#include "canvas.h"
#include <QtWidgets>
#include <cmath>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{
    _pointsNumber = 10;
}

void Canvas::resizeEvent(QResizeEvent *event)
{
    pixmap = QPixmap(event->size());
    drawGraph(_pointsNumber);
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap);
}

void Canvas::drawGraph(int n)
{
    pixmap.fill(Qt::white);
    QPainter painter(&pixmap);
    painter.setRenderHint(QPainter::Antialiasing, true);

    const int R = 3;
    std::vector<QPoint> points = getPoints(n);

    painter.setPen(QPen(QBrush(Qt::black), 0.5));
    for (size_t i = 0; i < points.size(); ++i) {
        for (size_t j = i; j < points.size(); ++j) {
            painter.drawLine(points[i], points[j]);
        }
    }

    painter.setPen(Qt::black);
    painter.setBrush(QBrush(Qt::black));
    for (size_t i = 0; i < points.size(); ++i) {
        painter.drawEllipse(points[i].rx() - R, points[i].ry() - R, 2*R, 2*R);

        QPoint c =  geometry().center();
        int labelX = (int)(1.12*(points[i].rx() - c.rx())) + c.rx() - 4;
        int labelY = (int)(1.12*(points[i].ry() - c.ry())) + c.ry() + 5;

        painter.drawText(QPoint(labelX, labelY), QString("%1").arg(i));
    }
}

std::vector<QPoint> Canvas::getPoints(int n)
{
    const double STEP = 2 * M_PI / n;
    std::vector<QPoint> v;

    for (double t = 0; t < 2 * M_PI - 0.0000001; t += STEP) {
        int x = static_cast<int>(180 * cos(t) + geometry().center().rx());
        int y = static_cast<int>(180 * sin(t) + geometry().center().ry());
        v.push_back(QPoint(x, y));
    }

    return v;
}

void Canvas::setPointsNumber(int newValue)
{
    _pointsNumber = newValue;
    drawGraph(_pointsNumber);
}
