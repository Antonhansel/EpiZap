#include "Connexion.hpp"
#include "MainUI.hpp"

Connexion::Connexion(MainUI *mainui)
{
  _mainUI = mainui;
  _window = new QWidget;
  _window->show();
  this->_window->setFixedSize(300, 400);
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
  _tempTeam = -2;
  _windowteam = new QWidget();
  _windowteam->setFixedSize(200, 200);
  _teamLayout = new QGridLayout();
  _teamLineEdit = new QLineEdit();
  _teamButton = new QPushButton();
  _teamButton->setText("Ok");
  _teamLayout->addWidget(_teamLineEdit, 0, 0);
  _teamLayout->addWidget(_teamButton, 1, 0);
  _windowteam->setLayout(_teamLayout);
}

Connexion::~Connexion(){}

void 	Connexion::connectSlots()
{
  QObject::connect(_connect, SIGNAL(clicked()), this,SLOT(teamName(void)));
  QObject::connect(_quit, SIGNAL(clicked()), this,SLOT(quit(void)));
}

void 	Connexion::quit()
{
	_window->close();
}

void  Connexion::getTeamName()
{
  bool present;

  this->hide();
  present = false;
  for (std::vector<std::string>::iterator it = _teamNamevec.begin(); it != _teamNamevec.end(); ++it)
  {
    if ((*it) == _teamLineEdit->text().toStdString())
    {
      _tempTeam++;
      present = true;
    }
  }
  if (!present)
    _teamNamevec.push_back(_teamLineEdit->text().toStdString());
  if (_tempTeam == 0)
   QObject::connect(_teamButton, SIGNAL(clicked()), this,SLOT(tryConnect(void)));
 else
  teamName();
}

void  Connexion::teamName()
{
  if (checkData(_team->text()))
  {
    if (_tempTeam == -2)
    {
      _window->hide();
      _tempTeam = _team->text().toInt();
      _windowteam->show();
      QObject::connect(_teamButton, SIGNAL(clicked()), this,SLOT(getTeamName(void)));
    }
    _teamName = "Team";
    _teamName += QString::number(_tempTeam);
    _teamLineEdit->setText(_teamName);
    _tempTeam--;
  }
  else
    tryConnect();
}

void 	Connexion::tryConnect()
{
 QTextCursor c;

 _connect->setEnabled(false);
 if (checkData(_port->text()) && checkData(_width->text()) && checkData(_height->text()) &&
  checkData(_client->text()) && checkData(_delay->text()) && checkData(_team->text()) && (_client->text().toInt() > 0))
 {
  _console->setHtml(_console->toHtml() + "<font color=\"Green\">*** TRYING TO CREATE SERVER ***\n</font>");
  if (isConnected())
  {
    std::cout << _teamNamevec.size() << std::endl;
    _mainUI->setServer(_server);
    _mainUI->setConsoleText(_console->toHtml());
    _window->hide();
    _windowteam->hide();
    for (std::vector<std::string>::iterator it = _teamNamevec.begin(); it != _teamNamevec.end(); ++it)
    {
      init_all_team(&_server, (char*)((*it).c_str()));
    }
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
  _connect->setText("Create");
  _mainLayout->addWidget(_portLabel, 0, 0);
  _mainLayout->addWidget(_port, 0, 1);
  _port->setText("4242");
  _mainLayout->addWidget(_widthLabel, 1, 0);
  _mainLayout->addWidget(_width, 1, 1);
  _width->setText("50");
  _mainLayout->addWidget(_heightLabel, 2, 0);
  _mainLayout->addWidget(_height, 2, 1);
  _height->setText("50");
  _mainLayout->addWidget(_clientLabel, 3, 0);
  _mainLayout->addWidget(_client, 3, 1);
  _client->setText("10");
  _mainLayout->addWidget(_teamLabel, 4, 0);
  _mainLayout->addWidget(_team, 4, 1);
  _team->setText("10");
  _mainLayout->addWidget(_delayLabel, 5, 0);
  _mainLayout->addWidget(_delay, 5, 1);
  _delay->setText("10");
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
 _width = new QLineEdit();
 _widthLabel = new QLabel();
 _widthLabel->setText("Width :");
 _height = new QLineEdit();
 _heightLabel = new QLabel();
 _heightLabel->setText("Height :");
 _client = new QLineEdit();
 _clientLabel = new QLabel();
 _clientLabel->setText("Nb of customer :");
 _team = new QLineEdit();
 _teamLabel = new QLabel();
 _teamLabel->setText("Nb of team :");
 _delay = new QLineEdit();
 _delayLabel = new QLabel();
 _delayLabel->setText("Delay :");	
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
    if (rx.indexIn(data) != -1)
      return (true);
    else
      _console->setHtml(_console->toHtml() + "<font color=\"Red\">[ERROR]: bad Value for\n</font>");
  }
  return (false);
}

Map   *Connexion::getMap() const
{
  return (_server.map);
}

bool  Connexion::isConnected()
{
  QString res;

  _server.port = _port->text().toInt();
  _server.nb_player_co = 0;
  _server.nb_player = _client->text().toInt() * _team->text().toInt();
  _server.nb_player_team = _client->text().toInt();
  _server.nb_teams = _team->text().toInt();
  _server.ctime = _delay->text().toInt();
  _server.initialize = FALSE;
  res = init_server(&_server, _width->text().toInt(), _height->text().toInt());
  _console->setHtml(_console->toHtml() + res);
  return (_server.initialize);
}
