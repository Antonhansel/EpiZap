#include "MainUI.hpp"

void	MainUI::applyLayouts()
{ 
  _mainLayout->setMenuBar(_menuBar);
  _mainLayout->addWidget(_connect, 2, 1);
  _mainLayout->addWidget(_quit, 3, 1);
  _mainLayout->addWidget(_console, 4, 1);
}

void MainUI::connectSlots()
{
  QObject::connect(_connect, SIGNAL(clicked()), this,SLOT(tryConnect(void)));
  QObject::connect(_quit, SIGNAL(clicked()), this,SLOT(quit(void)));
}

void  MainUI::menuBar()
{
  _menuBar = new QMenuBar;
  _fileMenu = new QMenu(tr("&File"), this);
  _about = _fileMenu->addAction(tr("About"));
  _exitAction = _fileMenu->addAction(tr("E&xit"));
  _menuBar->addMenu(_fileMenu);

  connect(_exitAction, SIGNAL(triggered()), qApp, SLOT(quit()));
  connect(_about, SIGNAL(triggered()), this, SLOT(showAbout()));
}

void  MainUI::tryConnect()
{
  _mainLayout->removeWidget(_quit);
  _mainLayout->addWidget(_console, 9, 1);
  _mainLayout->addWidget(_portLabel, 3, 0);
  _mainLayout->addWidget(_port, 3, 1);
  _mainLayout->addWidget(_widthLabel, 4, 0);
  _mainLayout->addWidget(_width, 4, 1);
  _mainLayout->addWidget(_heightLabel, 5, 0);
  _mainLayout->addWidget(_height, 5, 1);
  _mainLayout->addWidget(_customerLabel, 6, 0);
  _mainLayout->addWidget(_customer, 6, 1);
  _mainLayout->addWidget(_delayLabel, 7, 0);
  _mainLayout->addWidget(_delay, 7, 1);
  _mainLayout->addWidget(_quit, 8, 1);

 /* sleep(5);

  _mainLayout->removeWidget(_quit);
  _mainLayout->removeWidget(_portLabel);
  _mainLayout->removeWidget(_port);
  _mainLayout->addWidget(_quit, 3, 1);*/
  std::cout << "TRY CONNECT" << std::endl;
}

void  MainUI::quit()
{
  exit(EXIT_SUCCESS);
}

void  MainUI::initConnexionStuff()
{
   _connect = new QPushButton(this);
   _connect->setText("Connect");
   _quit = new QPushButton(this);
   _quit->setText("Quit");
   _console = new QTextEdit();
   _console->setReadOnly(true);
   _console->setEnabled(false);
   _port = new QLineEdit();
   _portLabel = new QLabel();
   _portLabel->setText("Port :");
   _width = new QLineEdit();
   _widthLabel = new QLabel();
   _widthLabel->setText("Width :");
   _height = new QLineEdit();
   _heightLabel = new QLabel();
   _heightLabel->setText("Height :");
   _customer = new QLineEdit();
   _customerLabel = new QLabel();
   _customerLabel->setText("Nb of customer :");
   _delay = new QLineEdit();
   _delayLabel = new QLabel();
   _delayLabel->setText("Delay :");
   _network = new Network();
   _mainGUI = new MainGUI(_network);
}

void	MainUI::initLayouts()
{
  menuBar();
  initConnexionStuff();
}

void	MainUI::initUi()
{
  _mainLayout = new QGridLayout;
  setFixedSize(HEIGHT, WIDTH);
  setWindowTitle(tr("Zappy Monitoring"));
}

void            MainUI::showAbout() const
{
  QMessageBox msgBox;

  msgBox.setText("- Zappyyyyy -");
  msgBox.setInformativeText("The worst project ever made\n");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.exec();
}

MainUI::MainUI() : QWidget()
{
  initUi();
  initLayouts();
  applyLayouts();
  connectSlots();
  setLayout(_mainLayout);
}

