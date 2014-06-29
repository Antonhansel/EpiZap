#include <iostream>
#include "NetworkC.hpp"

NetworkC::NetworkC(Server *server, QTextEdit *console) : _server(server), _console(console)
{
}
 
NetworkC::~NetworkC()
{
}
 
void	NetworkC::doWork()
{
	_server->loop(_server);
}