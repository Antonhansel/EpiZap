#include "../header/myIA.hpp"

myIA::myIA() 
{
	_isAlive = true;
	_range = 1;
	_fl = 0;
	_startsearch = 0;
	_dim = std::make_pair(10, 10);
}

myIA::~myIA() {}

bool				myIA::initLoop(const std::string &ipAddr, const std::string &team, const int port)
{
	_ipAddr = ipAddr;
	_port = port;
	_teamName = team;
	_socket = -1;
	_run = initSocket();
	return (_run);
}

bool			myIA::initSocket()
{
  struct protoent	*pe;
  struct sockaddr_in	sin;

  if (_socket != -1)
    {
      close(_socket);
      _socket = -1;
    }
  if ((pe = getprotobyname("TCP")) == NULL)
    return (false);
  if ((_socket = socket(AF_INET, SOCK_STREAM, pe->p_proto)) == -1)
    return (false);
  sin.sin_family = AF_INET;
  sin.sin_port = htons(_port);
  sin.sin_addr.s_addr = inet_addr(_ipAddr.c_str());
  if (connect(_socket,
	      (const struct sockaddr *)&sin, sizeof(sin)) == -1)
    {
      close(_socket);
      _socket = -1;
      return (false);
    }
  return (true);
}

void		myIA::checkBitsField(fd_set *readfds, fd_set *writefds)
{
	if (FD_ISSET(_socket, writefds))
	{
		fctWrite();
	}
	else if (FD_ISSET(_socket, readfds))
	{
		fctRead();
	}
}

bool			myIA::fctWrite()
{
	unsigned int ret;

	if ((ret = write(_socket, _send.front().c_str(), _send.front().length())) > 0)
	{
		_send.pop_front();
	}
	return (true);
}

bool		myIA::socketProblem()
{
	close(_socket);
	return (false);
}

bool		myIA::fctRead()
{
	char	buf[512];
	int 	ret;
	std::string 	t;

	memset(buf, 0, 512);
	if ((ret = read(_socket, buf, 511)) > 0)
	{
		std::string	*s;
		s = new std::string(buf);
		if (s->compare("BIENVENUE\n") == 0)
		{
			_send.push_back(_teamName);
		}
		else
			_receive.push_back(*s);
		_fl++;
		std::cout << "|" << buf << "|" << std::endl;
	}
	else
		return (socketProblem());
	return (true);
}

void 				myIA::loop()
{
	fd_set 			readfds;
	fd_set 			writefds;
	struct timeval	tv;
	bool			flag;

	flag = true;
	tv.tv_usec = 12000;
	while (_run && _isAlive)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		if (_send.size() > 0 && flag == false)
		{
			FD_SET(_socket, &writefds);
			flag = true;
		}
		else
		{
			FD_SET(_socket, &readfds);
			flag = false;
		}
		if (select(_socket + 1, &readfds, &writefds, NULL, &tv) != -1)
		{
			checkBitsField(&readfds, &writefds);
		}
		else
			std::cerr << "[ERROR]: error on select" << std::endl;
	}
}