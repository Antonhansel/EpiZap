#include "Network.hpp"

Network::Network()
{
  QWidget *_window = new QWidget;

  _window->show();
  _window->setFixedSize(600, 800);
  _mainLayout = new QGridLayout();
  QSize size = sizeHint();
  QDesktopWidget* desktop = QApplication::desktop();
  int width = desktop->width();
  int height = desktop->height();
  int mw = size.width();
  int mh = size.height();
  int centerW = (width/2) - (mw/2);
  int centerH = (height/2) - (mh/2);
  _window->move(centerW, centerH);
  _console = new QTextEdit(_window);
  _console->setReadOnly(true);
  _console->setEnabled(false);
  _console->setStyleSheet("color: green ; background-color: black");
  _mainLayout->addWidget(_console, 0, 0);
  _window->setLayout(_mainLayout);
}

Network::~Network()
{
	
}

void  Network::setConsoleText(const QString &data)
{
  _console->setHtml(data);
}