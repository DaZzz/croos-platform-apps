#include <QApplication>
#include <QLabel>
#include <QPushButton>

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  QPushButton *pButton = new QPushButton("&Hello world!");
  QObject::connect(pButton, SIGNAL(clicked()), &app, SLOT(quit()));
  pButton->show();
  return app.exec();
}