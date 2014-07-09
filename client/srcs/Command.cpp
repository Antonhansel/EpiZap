#include "../header/Command.hpp"

Command::Command()
{
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
			_send.push_back("avance");
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
				_send.push_back("gauche");
			else
				_send.push_back("droite");
			_ignore++;
		}
		else
			usleep(100000);
}

std::string		Command::cmdBroadcast(const std::string &message)
{
	bool		send = false;
	bool		recieve = false;
	std::string	str = "";

	while (!send)
	{
		if (_send.size() < 10)
		{
			_send.push_back(message);
			send = true;
		}
		else
			usleep(100000);
	}
	while (!recieve)
	{
		// MUTEX TODO
		str = _recieve.back();
		_recieve.pop_back();
		if (checkBroadcast(str) == true)
		{
			if (_type.compare("broadcast") && _level == _range)
				return (_order);
		}
		usleep(100000);
	}
	return (str);
}

bool			Command::checkBroadcast(std::string &str)
{
	size_t		begin;
	size_t		end;

	begin = str.find("[") + 1;
	end = str.find("]");
	_type = str.substr(begin, end - begin + 1);
	str = str.substr(2);
	begin = str.find("[") + 1;
	end = str.find("]");
	_order = str.substr(begin, end - begin + 1);
	str = str.substr(2);
	begin = str.find("[") + 1;
	end = str.find("]");
	_level = atoi(str.substr(begin, end - begin + 1).c_str());
	str = str.substr(2);
	return (true);
}

bool Command::checkRecieve(std::string str)
{
	if (str.find("deplacement") >= 0)
		return (true);
	if (str.find("message") >= 0)
		return (true);
	return (false);
}

std::string Command::cmdSee()
{
	bool send = false;
	bool recieve = false;
	std::string see;

	while (!send)
	if (_send.size() < 10)
	{
		_send.push_back("voir");
		send = true;
	}
	else
		usleep(100000);
	while (_ignore-- > 0)
	if (!checkRecieve(_recieve.front()))
		_recieve.pop_front();
	else
		usleep(100000);
	while (!recieve)
	{
		if (!checkRecieve(_recieve.front()))
		{
			see = _recieve.front();
			recieve = true;
		}
		else
			usleep(100000);
		_recieve.pop_front();
	}
	return (see);
}

bool Command::cmdTake(std::string)
{
	bool send = false;
	bool recieve = false;
	std::string ret;

	while (!send)
	if (_send.size() < 10)
	{
		_send.push_back("voir");
		send = true;
	}
	else
		usleep(100000);
	while (_ignore-- > 0)
		if (!checkRecieve(_recieve.front()))
			_recieve.pop_front();
		else
			usleep(100000);
	while (!recieve)
	{
		if (!checkRecieve(_recieve.front()))
		{
			ret = _recieve.front();
			recieve = true;
		}
		else
			usleep(100000);
		_recieve.pop_front();
	}
	if (ret.find("ok") >= 0)
		return (true);
	return (false);
}