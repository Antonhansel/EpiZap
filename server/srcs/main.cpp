#include "MainUI.hpp"
#include "Graphic.hpp"
#include <QtCore>
#include <QFont>
#include <QPainter>
#include <QDesktopServices>
#include <QtWidgets/QApplication>

int  convertToInt(const std::string &s)
{
  std::istringstream iss(s);
  int        val = 0;

  iss >> val;
  return (val);
}

void  setArgument(char **argv, int argc, bool &status, std::map<std::string, int> &flags)
{
  flags["-p"] = 0;
  flags["-x"] = 0;
  flags["-y"] = 0;
  flags["-c"] = 0;
  flags["-t"] = 0;
  for (int j(0); j != argc; j++)
  {
    if (std::string(argv[j]) == "-graphic")
      status = true;
    for (std::map<std::string, int>::iterator it = flags.begin(); it != flags.end(); ++it)
      if (it->first == argv[j] && ((j + 1) <= argc))
          it->second = convertToInt(argv[j + 1]);
  }
}


int		main(int argc, char **argv)
{
  bool    status(false);
  std::map<std::string, int> flags;
  
  setArgument(argv, argc, status, flags);
  QApplication  app(argc, argv);
  MainUI  Client(status, flags);
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
