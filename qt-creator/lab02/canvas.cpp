#include "canvas.h"
#include <QtWidgets>

Canvas::Canvas(QWidget *parent) :
    QWidget(parent)
{

}

void Canvas::resizeEvent(QResizeEvent *event)
{
    pixmap = QPixmap(event->size());
    pixmap.fill(Qt::white);

    QPainter painter(&pixmap);
    painter.drawText(20, 20, tr("Приветик"));
}

void Canvas::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.drawPixmap(0, 0, pixmap);
}
