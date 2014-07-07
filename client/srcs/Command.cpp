#include "Command.hpp"

Command::Command()
{
	_ignore = 0;
}

~Command()
{
}

void			Command::cmdMove()
{
	bool		send = false;

	while (!send)
		if (_send.size() < 10)
		{
			_send.push_back("avance");
			_ignore++;
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

std::string		Command::cmdSee()
{
	bool		send = false;
	bool		recieve = false;

	while (!send)
		if (_send.size() < 10)
		{
			_send.push_back("voir");
			send = true;
		}
		else
			usleep(100000);
	while (_ignore-- > 0 && _recieve.size() > 0)
		if (!checkRecieve())
			_recieve.pop_front();
	while (!recieve)
	{
		if (!checkRecieve())
		{
		}
	}
}

bool			Command::cmdTake(std::string)
{

}
