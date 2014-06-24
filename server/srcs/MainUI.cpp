#include "MainUI.hpp"

void	MainUI::applyLayouts(){}

void MainUI::connectSlots(){}

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

void  MainUI::initConnexionStuff()
{
  _connexion = new Connexion(this, _network);
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
  setWindowTitle(tr("Zappy Monitoring GUI"));
  _console = new QTextEdit(this);
  _console->setReadOnly(true);
  _console->setEnabled(false);
  _mainLayout->addWidget(_console, 0, 0);
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

void  MainUI::setConsoleText(const QString &data)
{
  _console->setHtml(data);
}