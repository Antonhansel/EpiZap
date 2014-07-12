#include <iostream>
#include "Network.hpp"

Network::Network(std::list<std::string> &receive, std::list<std::string> &send, const std::string &ipAddr, int port, const std::string &team) :
	_receive(receive), _send(send), _ipAddr(ipAddr), _port(port)
{
	_run = true;
	if ((_circularBuffer = (CircularBuffer*)malloc(sizeof(CircularBuffer))) == NULL)
		_run = false;
	if (_run == true && createCircularBuffer(&_circularBuffer) == false)
		_run = false;
	if (initSocket() == false)
		_run = false;
	_send.push_back(team);
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

	if ((pe = getprotobyname("TCP")) == NULL)
		return (false);
 	if ((_fd = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
 		return (false);
 	sin.sin_family = AF_INET;
  	sin.sin_port = htons(_port);
	sin.sin_addr.s_addr = inet_addr(_ipAddr.c_str());
  	if (xconnect(_fd, &sin, sizeof(sin)) == -1)
    {
      close(_fd);
      _fd = -1;
      return (false);
    }
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
	if ((ret = write(_fd, ptr->c_str(), ptr->length())) > 0)
	{
		resetElemInBuffer(&_circularBuffer, ret + 1);
		if (ret == ptr->length())
		{
			_circularBuffer = _circularBuffer->head;
			_send.pop_front();
			std::cout << "STACK SIZE = " << _send.size() << std::endl;
			_action = SEND;
			usleep(20000);
			std::cout << "SENT |" << *ptr << "|" << std::endl;
			std::cout << "SENTED " << ret << " ON " << ptr->length() << std::endl;
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
			resetElemInBuffer(&_circularBuffer, ret + 1);
			_circularBuffer = _circularBuffer->head;
			_receive.push_back(*s);
			std::cout << "|" << buf << "|" << std::endl;	
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
	_send.push_back("avance\n");
	_send.push_back("avance\n");
	_send.push_back("avance\n");
	_send.push_back("avance\n");
	_send.push_back("droite\n");
	_send.push_back("avance\n");
	_send.push_back("gauche\n");
	_send.push_back("gauche\n");
	_send.push_back("avance\n");
	_send.push_back("avance\n");
	while (_run)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		if (_send.size() > 0 && (i == 1 || i > 2))
		{
			std::cout << "WRITE LOOP NEXT\n";
			FD_SET(_fd, &writefds);
			if (_action == SEND)
			{
				_action = NOT_SEND;
				addStrInBuffer(&_circularBuffer, _send.front().c_str());
				_circularBuffer = _circularBuffer->head;

				CircularBuffer *tmp;
				tmp = _circularBuffer;
				int j = 0;
				while (tmp && j < BUFFER_SIZE)
				{
					std::cout << tmp << " WITH HEAD = " << tmp->head << " " << tmp->c << std::endl; 
					tmp = tmp->next;
					++j;
				}
			}
			_mode = WRITE;
		}
		else
		{
			FD_SET(_fd, &readfds);
			_mode = READ;			
		}
		if (select(_fd + 1, &readfds, &writefds, NULL, NULL) != -1)
		{
			checkBitsField(&readfds, &writefds);
		}
		i++;
	}
}

