#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>

class Canvas : public QWidget
{

    Q_OBJECT

private:
    QImage image;

    void drawImage();

public:
    explicit Canvas(QWidget *parent = 0);
    const  QImage &getImage() const;
    void setNewImage(const QImage &image);

protected:
    void paintEvent(QPaintEvent *);

};

#endif // CANVAS_H
