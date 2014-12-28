#include "canvas.h"
#include <QtWidgets>
//#include <QtWidgets>

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

void Canvas::setNewImage(QString &filePath)
{
    image.load(filePath);
    drawImage();
}

void Canvas::applySchar()
{

}

void Canvas::drawImage()
{
    QPainter painter(this);
    pixmap.fill(Qt::white);
    painter.drawPixmap(0, 0, pixmap);
    painter.drawImage(0, 0, image);
}
