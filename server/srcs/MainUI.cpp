#include "MainUI.hpp"

void	MainUI::applyLayouts()
{
  if (_status)
  {
    _graphic = new Graphic(this);
  _rightLayout->addWidget(_graphic, 0, 0);
  _continue = true;
  _leftLayout->addWidget(_infos, 0, 0);
  _leftLayout->addWidget(_curplayer, 1, 0);
  _bottomLayout->addWidget(_teams, 0, 0);
  _bottomLayout->addWidget(_console, 0, 1);
  }
  else
      _bottomLayout->addWidget(_console, 0, 0);
  _topLayout->addLayout(_leftLayout, 0, 0);
  _mainLayout->addLayout(_topLayout, 0, 0);
  _topLayout->addLayout(_rightLayout, 0, 1);
  _mainLayout->addLayout(_bottomLayout, 1, 0);
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

void  MainUI::initConnexionStuff(std::map<std::string, int> &option)
{
  _connexion = new Connexion(this, option);
}

void MainUI::startGraphic()
{
  if (_status)
  _graphic->initRealUpdate(_connexion->getServer());
}

void	MainUI::initLayouts(std::map<std::string, int> &option)
{
  menuBar();
  initConnexionStuff(option);
}

void	MainUI::initUi()
{
  _leftLayout = new QGridLayout;
  _mainLayout = new QGridLayout;
  _bottomLayout = new QGridLayout;
  _topLayout = new QGridLayout;
  _rightLayout = new QGridLayout;
  setWindowTitle(tr("Zappy Monitoring GUI"));
  _console = new QTextEdit(this);
  _console->setReadOnly(true);
  _console->append("[CONSOLE] console started");
  _console->setStyleSheet("color: green; background-color: black");
  _console->setFixedHeight(HEIGHT/6);
  _infos = new QTextEdit(this);
  _infos->setText("Click on a square to reveal its data");
  _infos->setReadOnly(true);
  _infos->setFixedWidth(WIDTH/6);
  _infos->setStyleSheet("color: white; background-image: url(./textures/bg.png)");
  _teams = new QTreeWidget(this);
  _teams->setFixedHeight(HEIGHT/6);
  _teams->setFixedWidth(WIDTH/6);
  _teams->setHeaderLabel("Teams - Slots");
  _curplayer = new QTextEdit(this);
  _curplayer->setFixedWidth(WIDTH/6);
  _curplayer->setReadOnly(true);
  _curplayer->setStyleSheet("color: white; background-image: url(./textures/bgbot.png)");
}

void            MainUI::setServer(t_server &s)
{
  _server = &s;
  NetworkC  *net = new NetworkC(&s, _console);
  QThread   *q = new QThread();
  net->moveToThread(q);
  connect(q, SIGNAL(started()), net, SLOT(doWork()));
  q->start();
  QTimer *timer = new QTimer(this);
  connect(timer, SIGNAL(timeout()), this, SLOT(updateInfos()));
  timer->start(1000/20);
  QTimer *timer2 = new QTimer(this);
  connect(timer2, SIGNAL(timeout()), this, SLOT(refreshList()));
  timer2->start(5);
}

void            MainUI::showAbout() const
{
  QMessageBox msgBox;

  msgBox.setText("- Zappyyyyy -");
  msgBox.setInformativeText("The worst project ever made\n");
  msgBox.setStandardButtons(QMessageBox::Ok);
  msgBox.exec();
}

void          MainUI::addData(QString const &data, bool clear)
{
  if (clear)
    _infos->clear();
  _infos->append(data);
}

void          MainUI::addData2(QString const &data, bool clear)
{
  if (clear)
    _curplayer->clear();
  _curplayer->append(data);
}

MainUI::MainUI(bool status, std::map<std::string, int> &option) : QWidget()
{
  _status = status;
  _graphic = NULL;
  initUi();
  initLayouts(option);
  applyLayouts();
  connectSlots();
  setLayout(_mainLayout);
}

void  MainUI::addToList(t_team *temp)
{
  QTreeWidgetItem   *teamName;
  QString         slotText;
  
  teamName = new QTreeWidgetItem(_teams);
  slotText = QString(temp->name);
  slotText += " - ";
  slotText += QString::number(temp->nb_player_actu);
  slotText += QString("/");
  slotText += QString::number(temp->nb_player_max);
  teamName->setText(0, slotText);
  _teams->addTopLevelItem(teamName);
}

void MainUI::refreshList()
{ 
  if (_status && _continue)
  {
    t_team  *temp;
    temp = _server->team;
    _teams->clear();
    while (temp != NULL)
    {
      addToList(temp);
      temp = temp->next;
    }
  }
}

void  MainUI::updateGraphic()
{
  if (_continue && _status)
  {
    _continue = _graphic->update();
    if (!_continue)
      delete _graphic;
  }
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