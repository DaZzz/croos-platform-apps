#include "main_window.h"
#include <QtWidgets>

MainWindow::MainWindow()
{
  QLabel *l1 = new QLabel("Label 1");
  QLabel *l2 = new QLabel("Label 2");
  setWindowTitle("Hello there!");
}