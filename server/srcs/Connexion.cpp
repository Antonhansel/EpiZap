#include "Connexion.hpp"

Connexion::Connexion(MainUI *mainui)
{
  _mainUI = mainui;
  _window = new QWidget();
  _window->show();
  init();
  setLayouts();
  connectSlots();
  tryConnect();
  _window->setLayout(_mainLayout);
}

void 	Connexion::connectSlots()
{
  QObject::connect(_connect, SIGNAL(clicked()), _window,SLOT(tryConnect(void)));
  QObject::connect(_quit, SIGNAL(clicked()), _window,SLOT(quit(void)));
}

void 	Connexion::tryConnect()
{
  // if (checkData(_port->text()) && checkData(_width->text()) && checkData(_height->text()) &&
  //     checkData(_client->text()) && checkData(_delay->text()))
  //   _console->setHtml(_console->toHtml() + "<font color=\"Green\">*** TRYING TO CREATE SERVER ***\n</font>"); 
  // else
  //   _console->setHtml(_console->toHtml() + "<font color=\"Red\">[ERROR]: Missing Arguments\n</font>");
	//_mainUI->show();
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
    _mainLayout->addWidget(_quit, 8, 1);
}

void 	Connexion::init()
{
	_mainLayout = new QGridLayout();
   _connect = new QPushButton(_window);
   _connect->setText("Start");
   _quit = new QPushButton(_window);
   _quit->setText("Quit");
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
}

Connexion::~Connexion()
{}
