#include "MainUI.hpp"

void	MainUI::applyLayouts()
{
  _leftLayout->addWidget(_infos, 0, 0);
  _leftLayout->addWidget(_teams, 1, 0);
  _bottomLayout->addWidget(_console, 0, 0);
  _topLayout->addLayout(_leftLayout, 0, 0);
  _mainLayout->addLayout(_topLayout, 0, 0);
  _mainLayout->addLayout(_bottomLayout, 0, 1);
}

void MainUI::connectSlots()
{
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateGraphic()));
  timer->start(50);
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
  _leftLayout = new QGridLayout;
  _mainLayout = new QGridLayout;
  _bottomLayout = new QGridLayout;
  _topLayout = new QGridLayout;
  setWindowTitle(tr("Zappy Monitoring GUI"));
  _console = new QTextEdit(this);
  _console->setReadOnly(true);
  _console->append("[CONSOLE] console started");
  _console->setStyleSheet("color: green; background-color: black");
  _infos = new QTextEdit(this);
  _infos->setText("DISPLAY DATA SELECTED");
  _infos->setReadOnly(true);
  _infos->setFixedWidth(WIDTH/3);
  _teams = new QTextEdit(this);
  _teams->setText("DISPLAY TEAMS");
  _teams->setReadOnly(true);
  _teams->setFixedWidth(WIDTH/3);
}

void            MainUI::setServer(Server &s)
{
  _server = &s;
  NetworkC  *net = new NetworkC(&s, _console);
  QThread   *q = new QThread();
  net->moveToThread(q);
  connect(q, SIGNAL(started()), net, SLOT(doWork()));
  q->start();
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateInfos()));
  timer->start(50);
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
  _graphic = NULL;
  initUi();
  initLayouts();
  applyLayouts();
  connectSlots();
  setLayout(_mainLayout);
}

void  MainUI::updateGraphic()
{
  if (!_graphic)
    _graphic = new Graphic(100, 100);
  _graphic->update();
}

void  MainUI::setConsoleText(const QString &data)
{
  QTextCursor c;

  _console->setHtml(data);
  c = _console->textCursor();
  c.movePosition(QTextCursor::End);
  _console->setTextCursor(c);
}

void  MainUI::updateInfos()
{
  QString res;

  res = _server->msg;
  if (res.length() > 0)
  {
    _console->append(_server->msg);
    memset(((void*)(_server->msg)), 0, 256);
  }
}