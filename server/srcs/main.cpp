#include "MainUI.hpp"
# include <QtCore>
# include <QFont>
# include <QPainter>
# include <QDesktopServices>
# include <QtWidgets/QApplication>


int		main(int argc, char **argv)
{
  QApplication	app(argc, argv);
  MainUI	Client;
  QSize size = Client.sizeHint();
  QDesktopWidget* desktop = QApplication::desktop();
  int width = desktop->width();
  int height = desktop->height();
  int mw = size.width();
  int mh = size.height();
  int centerW = (width/2) - (mw/2);
  int centerH = (height/2) - (mh/2);
  Client.setFixedSize(mw/2, mh/2);
  Client.move(centerW, centerH);
  return (app.exec());
}
