#include "canvas.h"
#include <QtWidgets>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;

QImage  cvMatToQImage( const cv::Mat &inMat )
   {
      switch ( inMat.type() )
      {
         // 8-bit, 4 channel
         case CV_8UC4:
         {
            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_ARGB32 );
            return image;
         }

         // 8-bit, 3 channel
         case CV_8UC3:
         {
            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_RGB888 );

            return image.rgbSwapped();
         }

         // 8-bit, 1 channel
         case CV_8UC1:
         {
            static QVector<QRgb>  sColorTable;

            // only create our color table once
            if ( sColorTable.isEmpty() )
            {
               for ( int i = 0; i < 256; ++i )
                  sColorTable.push_back( qRgb( i, i, i ) );
            }

            QImage image( inMat.data, inMat.cols, inMat.rows, inMat.step, QImage::Format_Indexed8 );

            image.setColorTable( sColorTable );

            return image;
         }

         default:
            qWarning() << "ASM::cvMatToQImage() - cv::Mat image type not handled in switch:" << inMat.type();
            break;
      }

      return QImage();
}

cv::Mat QImageToCvMat( const QImage &inImage, bool inCloneImageData = true )
   {
      switch ( inImage.format() )
      {
         // 8-bit, 4 channel
         case QImage::Format_RGB32:
         {
            cv::Mat  mat( inImage.height(), inImage.width(), CV_8UC4, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine() );

            return (inCloneImageData ? mat.clone() : mat);
         }

          // 8-bit, 4 channel
          case QImage::Format_ARGB32:
          {
             cv::Mat  mat( inImage.height(), inImage.width(), CV_8UC4, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine() );

             return (inCloneImageData ? mat.clone() : mat);
          }

         // 8-bit, 3 channel
         case QImage::Format_RGB888:
         {
            if ( !inCloneImageData )
               qWarning() << "ASM::QImageToCvMat() - Conversion requires cloning since we use a temporary QImage";

            QImage   swapped = inImage.rgbSwapped();

            return cv::Mat( swapped.height(), swapped.width(), CV_8UC3, const_cast<uchar*>(swapped.bits()), swapped.bytesPerLine() ).clone();
         }

         // 8-bit, 1 channel
         case QImage::Format_Indexed8:
         {
            cv::Mat  mat( inImage.height(), inImage.width(), CV_8UC1, const_cast<uchar*>(inImage.bits()), inImage.bytesPerLine() );

            return (inCloneImageData ? mat.clone() : mat);
         }

         default:
            qWarning() << "ASM::QImageToCvMat() - QImage format not handled in switch:" << inImage.format();
            break;
      }

      return cv::Mat();
}

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
}

void Canvas::applySchar()
{
    Mat src, src_gray;
    Mat grad;
    int scale = 1;
    int delta = 0;
    int ddepth = CV_16S;

    // Load an image
    src = QImageToCvMat(image, true);

    if( !src.data )
    { return; }

    cvtColor( src, src_gray, CV_RGB2GRAY );

    // Generate grad_x and grad_y
    Mat grad_x, grad_y;
    Mat abs_grad_x, abs_grad_y;

    // Gradient X
    Scharr( src_gray, grad_x, ddepth, 1, 0, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_x, abs_grad_x );

    // Gradient Y
    Scharr( src_gray, grad_y, ddepth, 0, 1, scale, delta, BORDER_DEFAULT );
    convertScaleAbs( grad_y, abs_grad_y );

    // Total Gradient (approximate)
    addWeighted( abs_grad_x, 0.5, abs_grad_y, 0.5, 0, grad );
    image = cvMatToQImage(grad);
}

void Canvas::drawImage()
{
    QPainter painter(this);
    pixmap.fill(Qt::white);
    painter.drawPixmap(0, 0, pixmap);
    painter.drawImage(0, 0, image);
}
