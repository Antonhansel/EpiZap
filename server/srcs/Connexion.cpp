#include "Connexion.hpp"
#include "MainUI.hpp"

Connexion::Connexion(MainUI *mainui, Network *network)
{
  _network = network;
  _mainUI = mainui;
  _window = new QWidget;
  _window->show();
  this->_window->setFixedSize(600, 600);
  this->_window->setWindowTitle(tr("Connexion"));
  init();
  setLayouts();
  connectSlots();
  _window->setLayout(_mainLayout);
  QSize size = sizeHint();
  QDesktopWidget* desktop = QApplication::desktop();
  int width = desktop->width();
  int height = desktop->height();
  int mw = size.width();
  int mh = size.height();
  int centerW = (width/2) - (mw/2);
  int centerH = (height/2) - (mh/2);
  _window->move(centerW, centerH);
}

Connexion::~Connexion(){}

void 	Connexion::connectSlots()
{
  QObject::connect(_connect, SIGNAL(clicked()), this,SLOT(tryConnect(void)));
  QObject::connect(_quit, SIGNAL(clicked()), this,SLOT(quit(void)));
}

void 	Connexion::quit()
{
	_window->close();
}

void 	Connexion::tryConnect()
{
  if (checkData(_port->text()) && checkData(_width->text()) && checkData(_height->text()) &&
      checkData(_client->text()) && checkData(_delay->text()))
  {
    _console->setHtml(_console->toHtml() + "<font color=\"Green\">*** TRYING TO CREATE SERVER ***\n</font>");
    _network->setConsoleText(_console->toHtml());
    _window->hide();
    _mainUI->show();
  }
  else
    _console->setHtml(_console->toHtml() + "<font color=\"Red\">[ERROR]: Missing Arguments\n</font>");
}

void 	Connexion::setLayouts()
{
    _connect->setText("Create");
    _mainLayout->addWidget(_portLabel, 3, 0);
    _mainLayout->addWidget(_port, 3, 1);
    _mainLayout->addWidget(_widthLabel, 4, 0);
    _mainLayout->addWidget(_width, 4, 1);
    _mainLayout->addWidget(_heightLabel, 5, 0);
    _mainLayout->addWidget(_height, 5, 1);
    _mainLayout->addWidget(_clientLabel, 6, 0);
    _mainLayout->addWidget(_client, 6, 1);
    _mainLayout->addWidget(_delayLabel, 7, 0);
    _mainLayout->addWidget(_delay, 7, 1);
    _mainLayout->addWidget(_connect, 8, 1);
    _mainLayout->addWidget(_quit, 9, 1);
    _mainLayout->addWidget(_console, 10, 1);
}

void 	Connexion::init()
{
   _mainLayout = new QGridLayout();
   _connect = new QPushButton(_window);
   _connect->setText("Start");
   _port = new QLineEdit();
   _portLabel = new QLabel();
   _portLabel->setText("Port :");
   _width = new QLineEdit();
   _widthLabel = new QLabel();
   _widthLabel->setText("Width :");
   _height = new QLineEdit();
   _heightLabel = new QLabel();
   _heightLabel->setText("Height :");
   _client = new QLineEdit();
   _clientLabel = new QLabel();
   _clientLabel->setText("Nb of customer :");
   _delay = new QLineEdit();
   _delayLabel = new QLabel();
   _delayLabel->setText("Delay :");	
   _quit = new QPushButton(_window);
   _quit->setText("Quit");
   _console = new QTextEdit();
   _console->setReadOnly(true);
   _console->setEnabled(false);
}

bool  Connexion::checkData(const QString &data)
{
  if (data.size() > 0)
  {
    QRegExp rx("^\\+?\\d+$");
    if (rx.indexIn(data) != -1)
      return (true);
    else
      _console->setHtml(_console->toHtml() + "<font color=\"Red\">[ERROR]: bad Value for\n</font>");
  }
  return (false);
}
