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
    drawImage();
}

void Canvas::setNewImage(const QImage &image)
{
    this->image = image;
    setMinimumSize(image.width(), image.height());
}

void Canvas::applySchar()
{

}

const QImage &Canvas::getImage() const
{
    return this->image;
}

void Canvas::drawImage()
{
    QPainter painter(this);
    painter.drawImage(0, 0, image);
}
