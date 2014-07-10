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
	_port = 4242;
	_ipAddr.assign("10.12.181.118");
	std::cout << "BEFORE INIT SOCKET\n";
	if (initSocket() == false)
		_run = false;
	std::cout << "AFTER INIT SOCKET\n";
	std::cout << "RUN = " << _run << std::endl;
	_mode = READ;
	_action = SEND;
}

Network::~Network()
{
}

bool	Network::initSocket()
{
	struct protoent		*pe;
	struct sockaddr_in	sin;

	std::cout << "BEFORE INIT SOCKET\n";

	if ((pe = getprotobyname("TCP")) == NULL)
		return (false);
 	if ((_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
 		return (false);
 	sin.sin_family = AF_INET;
  	sin.sin_port = htons(_port);
	sin.sin_addr.s_addr = inet_addr(_ipAddr.c_str());
	std::cout << "BEFORE INIT SOCKET\n";

  	if (xconnect(_fd, &sin, sizeof(sin)) == -1)
    {
		std::cout << "1111111BEFORE INIT SOCKET\n";

      close(_fd);
      _fd = -1;
      return (false);
    }
	std::cout << "BEFORE INIT SOCKET\n";

	return (true);
}

void		Network::checkBitsField(fd_set *readfds, fd_set *writefds)
{
	if (FD_ISSET(_fd, writefds))
	{
		fctWrite();
	}
	else if (FD_ISSET(_fd, readfds))
	{
		std::cout << "READ LOOP NEXT\n";
		fctRead();
	}
}

bool			Network::fctWrite()
{
	std::string	*ptr;
	unsigned int ret;

	ptr = getDataOfBuffer(_circularBuffer);
	std::cout << "TO SEND = " << *ptr << std::endl; 
	ptr->push_back('\n');
	if ((ret = write(_fd, ptr->c_str(), ptr->length())) > 0)
	{
		resetElemInBuffer(&_circularBuffer, ret);
		if (ret == ptr->length())
		{
			_circularBuffer = _circularBuffer->head;
			_send.pop_front();
			_action = SEND;
		}
		delete ptr;
	}
	return (true);
}

bool		Network::socketProblem()
{
	close(_fd);
	return (false);
}

bool		Network::fctRead()
{
	char	buf[512];
	int 	ret;

	memset(buf, 0, 512);
	if ((ret = read(_fd, buf, 511)) > 0)
	{
		_circularBuffer = _circularBuffer->head;
		if (!(addStrInBuffer(&_circularBuffer, buf)))
			return (false);
		else
		{
			std::string	*s;
			_circularBuffer = _circularBuffer->head;
			s = getDataOfBuffer(_circularBuffer);
			std::cout << "|" << *s << "|" << std::endl;	
		}
	}
	else
		return (socketProblem());
	return (true);
}

void		Network::doWork()
{
	fd_set 	readfds;
	fd_set 	writefds;

	int 	i;

	i = 0;
	_send.push_back("Team10\n");
	while (_run)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		if (_send.size() > 0 && i > 0)
		{
			std::cout << "SEND\n";
			FD_SET(_fd, &writefds);
			if (_action == SEND)
			{
				addStrInBuffer(&_circularBuffer, _send.front().c_str());
				_action = NOT_SEND;
			}
			_mode = WRITE;
		}
		else
		{
			std::cout << "READ LOOP\n";
			FD_SET(_fd, &readfds);
			_mode = READ;			
		}
		if (select(_fd + 1, &readfds, &writefds, NULL, NULL) != -1)
		{
			checkBitsField(&readfds, &writefds);
		}
		std::cout << "DOING JOB..." << std::endl;
		++i;
	}
}

