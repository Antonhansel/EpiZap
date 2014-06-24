#include <iostream>
#include "NetworkC.hpp"

NetworkC::NetworkC(Server *server) :
	_server(server)
{
}
 
NetworkC::~NetworkC()
{
}
 
void NetworkC::doWork()
{
  	std::cout << "ADDR SERVER = " << _server << " && PORT NB = " << _server->socket << std::endl;
	serverLoop(_server);
}