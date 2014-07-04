#include "Connexion.hpp"
#include "MainUI.hpp"

Connexion::Connexion(MainUI *mainui)
{
  _mainUI = mainui;
  _window = new QWidget;
  _window->show();
  this->_window->setFixedSize(300, 300);
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
   QTextCursor c;

   _connect->setEnabled(false);
   if (checkData(_ip->text()) && checkData(_port->text()))  
   {
    _console->setHtml(_console->toHtml() + 
     "<font color=\"Green\">*** TRYING CONNECT TO SERVER ***\n</font>");
    if (isConnected())
    {
     _mainUI->setConsoleText(_console->toHtml());
     _window->hide();
     _mainUI->show();
     _mainUI->startGraphic();
   }
  }
  else
   _console->setHtml(_console->toHtml() + "<font color=\"Red\">[ERROR]: Missing Arguments\n</font>");
  c = _console->textCursor();
  c.movePosition(QTextCursor::End);
  _console->setTextCursor(c);
  _connect->setEnabled(true);
}

void 	Connexion::setLayouts()
{
    _connect->setText("Join");
    _mainLayout->addWidget(_ipLabel, 0, 0);
    _mainLayout->addWidget(_ip, 0, 1);
    _ip->setText("127.0.0.1");
    _mainLayout->addWidget(_portLabel, 1, 0);
    _mainLayout->addWidget(_port, 1, 1);
    _port->setText("4242");
    _mainLayout->addWidget(_connect, 6, 0, 1, 2);
    _mainLayout->addWidget(_quit, 7, 0, 1, 2);
    _mainLayout->addWidget(_console, 8, 0, 1, 2);
}

void 	Connexion::init()
{
  _mainLayout = new QGridLayout();
  _connect = new QPushButton(_window);
  _connect->setText("Start");
  _port = new QLineEdit();
  _portLabel = new QLabel();
  _portLabel->setText("Port :");
  _ip = new QLineEdit();
  _ipLabel = new QLabel();
  _ipLabel->setText("IP :");
  _quit = new QPushButton(_window);
  _quit->setText("Quit");
  _console = new QTextEdit();
  _console->setReadOnly(true);
}

bool  Connexion::checkData(const QString &data)
{
  if (data.size() > 0)
  {
    QRegExp rx("^\\+?\\d+$");
    QRegExp ip("^[\\d]{1,3}\\.[\\d]{1,3}\\.[\\d]{1,3}\\.[\\d]{1,3}$");
    
    if (rx.indexIn(data) != -1 || ip.indexIn(data) != -1)
      return (true);
    else
      _console->setHtml(_console->toHtml() + "<font color=\"Red\">[ERROR]: bad Value\n</font>");
  }
  return (false);
}

bool  Connexion::isConnected()
{
  // QString res;

  // _server.port = _port->text().toInt();
  // _server.nb_player_co = 0;
  // _server.nb_player = _client->text().toInt() * _team->text().toInt();
  // _server.nb_player_team = _client->text().toInt();
  // _server.nb_teams = _team->text().toInt();
  // _server.ctime = _delay->text().toInt();
  // _server.initialize = FALSE;
  // res = init_server(&_server, _width->text().toInt(), _height->text().toInt());
  // _console->setHtml(_console->toHtml() + res);
  return (true);
}
