#include "MainUI.hpp"

void	MainUI::applyLayouts()
{ 
  _mainLayout->setMenuBar(_menuBar);
  _mainLayout->addWidget(_ip, 0, 1);
  _mainLayout->addWidget(_ipLabel, 0, 0);
  _mainLayout->addWidget(_port, 1, 1);
  _mainLayout->addWidget(_portLabel, 1, 0);
  _mainLayout->addWidget(_connect, 2, 1);
}

void MainUI::connectSlots()
{
  QObject::connect(_connect, SIGNAL(clicked()), this,SLOT(tryConnect(void)));
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
  std::cout << "TRY CONNECT" << std::endl;
}

void  MainUI::initConnexionStuff()
{
   _ip = new QLineEdit(this);
   _ipLabel = new QLabel(this);
   _ipLabel->setText("IP ");
   _ipLabel->setFixedWidth(30);
   _port = new QLineEdit(this);
   _portLabel = new QLabel(this);
   _portLabel->setText("PORT ");
   _connect = new QPushButton(this);
   _connect->setText("Connect!");
   _network = new Network();
   //setter pour l'ip/port
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
  setWindowTitle(tr("Zappyyyyy"));
  setStyleSheet("color: #CFD6D7; background-color: #403075");
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

