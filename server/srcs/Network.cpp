#include "Network.hpp"

Network::Network()
{
  QWidget *_window = new QWidget;

  _window->show();
  _window->setFixedSize(600, 800);
  _mainLayout = new QGridLayout();
  _console = new QTextEdit(_window);
  _console->setReadOnly(true);
  _console->setEnabled(false);
  _console->setStyleSheet("color: green ; background-color: black");
  _mainLayout->addWidget(_console, 0, 0);
  _window->setLayout(_mainLayout);
  _window->move(100, 100);
}

Network::~Network()
{
	
}

void  Network::setConsoleText(const QString &data)
{
  _console->setHtml(data);
}