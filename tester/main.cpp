#include <QtCore>
#include <QFont>
#include <QPainter>
#include <QDesktopServices>
#include <QtWidgets/QApplication>
# include "MainUI.hpp"

int		main(int argc, char **argv)
{
  QApplication	app(argc, argv);
  MainUI	Client;
  // Client.setFixedSize(, 878);
  // Client.move(centerW, centerH);
  return (app.exec());
}
