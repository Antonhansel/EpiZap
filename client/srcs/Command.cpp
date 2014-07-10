#include "../header/Command.hpp"

Command::Command()
{
	_ignore = 0;
	_dir = 1;
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
			_dir *= -1;
			_ignore++;
		}
		else
			usleep(100000);
}
 
bool 			Command::checkRecieve(std::string str)
{
	if (str.empty())
		return (false);
	if (str.find("deplacement") != std::string::npos)
		return (true);
	else if (str.find("message") != std::string::npos)
		return (true);
	return (false);
}

std::string 	Command::cmdSee()
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
		if (!_recieve.empty() && !checkRecieve(_recieve.front()))
		{
			_recieve.pop_front();
			_ignore--;
		}
		else
			usleep(100000);
	while (!recieve)
	{
			std::cout << "wait answer of the server" << std::endl;
		if (!_recieve.empty() && !checkRecieve(_recieve.front()))
		{
			see = _recieve.front();
			recieve = true;
		}
		else
			usleep(100000);
		if (!_recieve.empty())
			_recieve.pop_front();
	}
	return (see);
}

bool			Command::cmdTake(std::string object)
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
		if (!_recieve.empty() && !checkRecieve(_recieve.front()))
		{
			_recieve.pop_front();
			_ignore--;
		}
		else
			usleep(100000);
	while (!recieve)
	{
		if (!_recieve.empty() && !checkRecieve(_recieve.front()))
		{
			ret = _recieve.front();
			recieve = true;
		}
		else
			usleep(100000);
		if (!_recieve.empty())
			_recieve.pop_front();
	}
	if (ret.find("ok") != std::string::npos)
		return (true);
	return (false);
}

///////////// BROADCAST ////////////////


//std::string		Command::reciveBroadcast()
// {
// 	bool		recieve = false;
// 	std::string	str = "";

// 	while (!recieve)
// 	{
// 		// MUTEX TODO
// 		str = _recieve.back();
// 		_recieve.pop_back();
// 		// if (checkRecieve(str) == true && checkBroadcast(str) == true)
// 		// {
// 		// 	if (_level == _range)
// 				// return (true);
// 		// }
// 		// usleep(100000);
// 	}
// 	return (str);
// }

// bool			Command::checkBroadcast(std::string &str)
// {
// 	size_t		begin;
// 	size_t		end;

// 	begin = str.find("message");
// 	if (begin == -1)
// 		return (false);
// 	str = str.substr(7);
// 	end = str.find(",");
// 	_k = atoi((str.substr(0, end)).c_str());
// 	str = str.substr(end + 2);
// 	begin = str.find("[") + 1;
// 	end = str.find("]");
// 	if (begin != -1 && end != -1)
// 		_order = str.substr(begin, end - begin);
// 	str = str.substr(end + 2, str.find("\n"));
// 	_level = atoi(str.c_str());
// 	_message = str;
// 	return (true);
// }


// bool			Command::cmdBroadcast(const std::string &message)
// {
// 	bool		send = false;

// 	while (!send)
// 	{
// 		if (_send.size() < 10)
// 		{
// 			_send.push_back(message);
// 			send = true;
// 		}
// 		else
// 			usleep(100000);
// 	}
// 	return (true);
// }