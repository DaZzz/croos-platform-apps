#include "mainwindow.h"
#include <QApplication>
#include "opencv2/core/core.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

int main(int argc, char *argv[])
{
    cv::Mat src1;
    src1 = cv::imread("/Users/DaZzz/Desktop/jpeg.jpg", CV_LOAD_IMAGE_COLOR);
    cv::namedWindow( "Original image", CV_WINDOW_AUTOSIZE );
    cv::imshow( "Original image", src1 );

    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();
}
