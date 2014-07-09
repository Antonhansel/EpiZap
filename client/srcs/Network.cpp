#include <iostream>
#include "Network.hpp"

Network::Network(std::list<std::string> &receive, std::list<std::string> &send) :
	_receive(receive), _send(send)
{
	_run = true;
	if ((_circularBuffer = (CircularBuffer*)malloc(sizeof(CircularBuffer))) == NULL)
		_run = false;
	if (_run == true && createCircularBuffer(&_circularBuffer) == false)
		_run = false;
	if (initSocket() == false)
		_run = false;
}

Network::~Network()
{
}

bool	Network::initSocket()
{
	struct protoent		*pe;
	struct sockaddr_in	sin;

	if ((pe = getprotobyname("TCP")) == NULL)
		return (false);
 	if ((_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
 		return (false);
 	sin.sin_family = AF_INET;
  	sin.sin_port = htons(_port);
	sin.sin_addr.s_addr = INADDR_ANY;
  	if (xconnect(_fd, &sin, sizeof(sin)) == -1)
    {
      close(_fd);
      _fd = -1;
      return (false);
    }
	return (true);
}

void	Network::doWork()
{
	if (_run == true)
	{

	}
	while (true)
	{
		std::cout << "DOING JOB..." << std::endl;		
	}
}

