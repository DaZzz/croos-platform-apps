#include "canvas.h"
#include <QtWidgets>

Canvas::Canvas(QWidget *parent) : QWidget(parent)
{
}

void Canvas::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawImage(0, 0, image);
}

void Canvas::setNewImage(const QImage &image)
{
    this->image = image;
    setMinimumSize(image.width(), image.height());
}

const QImage &Canvas::getImage() const
{
    return this->image;
}
