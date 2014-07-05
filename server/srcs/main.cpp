#include "MainUI.hpp"
#include "Graphic.hpp"
#include <QtCore>
#include <QFont>
#include <QPainter>
#include <QDesktopServices>
#include <QtWidgets/QApplication>


int		main(int argc, char **argv)
{
  bool    status;
  if (argc == 2)
    status = true;
  else
    status = false;
  QApplication  app(argc, argv);
  MainUI  Client(status);
  QSize size = Client.sizeHint();
  QDesktopWidget* desktop = QApplication::desktop();
  srand(time(NULL));
  int width = desktop->width();
  int height = desktop->height();
  int mw = size.width();
  int mh = size.height();
  int centerW = (width/2) - (mw/2);
  int centerH = (height/2) - (mh/2);
  Client.setFixedSize(1725, 878);
  Client.move(centerW, centerH);
  return (app.exec());
}
