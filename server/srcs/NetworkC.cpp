#include <iostream>
#include "NetworkC.hpp"

NetworkC::NetworkC(Server *server, QTextEdit *console) :
	_server(server), _console(console)
{
	QTimer *timer = new QTimer(this);
	connect(timer, SIGNAL(timeout()), this, SLOT(updateInfos()));
	timer->start(50);
}
 
NetworkC::~NetworkC()
{
}
 
void	NetworkC::doWork()
{
	serverLoop(_server);
}

void	NetworkC::updateInfos()
{
	std::cout << "Update\n";
	_console->append(_server->msg);
	memset(((void*)(_server->msg)), 0, 256);
}