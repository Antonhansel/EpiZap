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
	while (42)
	{
		std::cout << "Do Work\n";
	}
}