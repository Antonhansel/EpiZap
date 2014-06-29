#include "MainUI.hpp"
#include "Graphic.hpp"
#include <QtCore>
#include <QFont>
#include <QPainter>
#include <QDesktopServices>
#include <QtWidgets/QApplication>


int		main(int argc, char **argv)
{
  QApplication	app(argc, argv);
  MainUI	Client;
  // Graphic test(15, 15);

  // try
  // {
  //   test.initSDL();
  // }
  // catch (const Erreur &e)
  // {
  //   std::cout << e.what()<< std::endl;
  // }
  QSize size = Client.sizeHint();
  QDesktopWidget* desktop = QApplication::desktop();
  int width = desktop->width();
  int height = desktop->height();
  int mw = size.width();
  int mh = size.height();
  int centerW = (width/2) - (mw/2);
  int centerH = (height/2) - (mh/2);
  Client.setFixedSize(1800, 900);
  Client.move(centerW, centerH);
  Client.show(); // to be removed

  return (app.exec());
}
