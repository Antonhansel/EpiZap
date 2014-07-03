#include <QtCore>
#include <QFont>
#include <QPainter>
#include <QDesktopServices>
#include <QtWidgets/QApplication>
# include "MainUI.hpp"

int		main(int argc, char **argv)
{
  QApplication	app(argc, argv);
  MainUI	Client(argv[1], argv[2], argv[3]);
  return (app.exec());
}
