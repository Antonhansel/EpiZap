#include "../header/Command.hpp"

Command::Command()
{
	_dir = 1;
	_ignore = 0;
}

Command::~Command()
{
}

void			Command::cmdMove(int size)
{
	bool		send = false;

	while (!send)
		if (_send.size() < 10)
		{
			_send.push_back("avance\n");
			_ignore++;
			size--;
			if (size == 0)
				send = true;
		}
		else
			usleep(100000);
}

void			Command::cmdRot(Direction dir)
{
	bool		send = false;

	while (!send)
		if (_send.size() < 10)
		{
			if (dir == LEFT)
				_send.push_back("gauche\n");
			else
				_send.push_back("droite\n");
			_ignore++;
			_dir *= -1;
		}
		else
			usleep(100000);
}

bool Command::checkRecieve(std::string str)
{
	if (str.empty())
		return (false);
	if (str.find("deplacement") != std::string::npos)
		return (true);
	if (str.find("message") != std::string::npos)
		return (true);
	return (false);
}

std::string Command::cmdSee()
{
	bool 		send = false;
	bool 		recieve = false;
	std::string see;

	while (!send)
	{
		if (_send.size() < 10)
		{
			_send.push_back("voir\n");
			send = true;
		}
		else
			usleep(100000);
	}
	while (_ignore > 0)
		if (!_receive.empty() && !checkRecieve(_receive.front()))
		{
			_receive.pop_front();
			_ignore--;
		}
		else
			usleep(100000);
	while (!recieve)
	{
			std::cout << "wait answer of the server" << std::endl;
		if (!_receive.empty() && !checkRecieve(_receive.front()))
		{
			see = _receive.front();
			recieve = true;
		}
		else
			usleep(100000);
		if (!_receive.empty())
			_receive.pop_front();
	}
	return (see);
}

bool Command::cmdTake(std::string object)
{
	bool 		send = false;
	bool 		recieve = false;
	std::string ret;

	while (!send)
		if (_send.size() < 10)
		{
			_send.push_back("prendre " + object + "\n");
			send = true;
		}
		else
			usleep(100000);
	while (_ignore > 0)
		if (!_receive.empty() && !checkRecieve(_receive.front()))
		{
			_receive.pop_front();
			_ignore--;
		}
		else
			usleep(100000);
	while (!recieve)
	{
		if (!_receive.empty() && !checkRecieve(_receive.front()))
		{
			ret = _receive.front();
			recieve = true;
		}
		else
			usleep(100000);
		if (!_receive.empty())
			_receive.pop_front();
	}
	if (ret.find("ok") != std::string::npos)
		return (true);
	return (false);
}