#include "canvas.h"
#include <QtWidgets>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{

}

void Canvas::resizeEvent(QResizeEvent *event)
{
    pixmap = QPixmap(event->size());
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    pixmap.fill(Qt::white);
    painter.drawPixmap(0, 0, pixmap);
}

void Canvas::setNewImage()
{

}

void Canvas::applySchar()
{

}
