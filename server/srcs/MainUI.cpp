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
  _connexion = new Connexion(this);
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
  _data = new QTextEdit(this);
  _data->setReadOnly(true);
  _data->setText("DISPLAY MAP");
  _infos = new QTextEdit(this);
  _infos->setText("DISPLAY DATA SELECTED");
  _infos->setReadOnly(true);
  _teams = new QTextEdit(this);
  _teams->setText("DISPLAY TEAMS");
  _teams->setReadOnly(true);
  _mainLayout->addWidget(_data, 0, 1, 2, 1);
  _mainLayout->addWidget(_infos, 0, 0, 1, 1);
  _mainLayout->addWidget(_teams, 1, 0, 1, 1);
  _mainLayout->addWidget(_console, 2, 0, 1, 2);
}

void            MainUI::setServer(Server *s)
{
  NetworkC  *net = new NetworkC(s);
  QThread   *q = new QThread();
  net->moveToThread(q);
  connect(q, SIGNAL(started()), net, SLOT(doWork()));
  q->start();
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
  QTextCursor c;

  _console->setHtml(data);
  c = _console->textCursor();
  c.movePosition(QTextCursor::End);
  _console->setTextCursor(c);
}