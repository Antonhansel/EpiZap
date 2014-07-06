#include "../header/myIA.hpp"

myIA::myIA() 
{
	_range = 1;
}

myIA::~myIA() {}

// bool				myIA::initLoop()
// {
// 	// bool			isAlive = true;
// 	// //Command 		lastCmd;
// 	// std::string		anwser;

// 	// initTabElevation();
// 	// while (isAlive == true)
// 	// {
// 	// 	//fillObjectifs();

// 	// 	while (_objectifs.size() > 1)
// 	// 	{
// 	// 		//searchRock();
// 	// 	}

// 	// 	// BROADCAST TODO

// 	// }
// 	return (true);
// }

void			myIA::initRock()
{
	_listRock.push_back("food");
	_listRock.push_back("linemate");
	_listRock.push_back("deraumere");
	_listRock.push_back("sibur");
	_listRock.push_back("mendiane");
	_listRock.push_back("phiras");
	_listRock.push_back("thystame");
}

// return TRUE si on a besoin de cet Object ou return FALSE
bool				myIA::isObject(std::string &object)
{
	int 	x = 0;

	while (x < _listRock.size())
	{
		if (object.compare(_listRock[x]) == 0)
		{
			return (true);
		}
		x++;
	}
	return (false);
}

// remplace tout les espaces par 0
std::string 	&myIA::replaceinString(std::string &str, const std::string &toFind, const std::string &toReplace)
{
	size_t pos = 0;
	for (pos = str.find(toFind); pos != std::string::npos; pos = str.find(toFind, pos))
	{
		str.replace(pos, 1, toReplace);
	}
	return(str);
}

// return ON si Object rechercher est a nos pied
// return FRONT si Object rechercher est devant nous
// return RIGHT si Object rechercher est a droitre
// return LEFT si Object rechercher est a guauche
// return NO si Object rechercher n'a pas était trouvé
Direction			myIA::checkRock(std::string &see)
{
	//std::string		see = cmdSee();
	int 			range = 0;
	int 			x = 0;
	Direction		arrow = FRONT;

	see = replaceinString(see, "{", "");
	see = replaceinString(see, "}", "");
	while (see != "")
	{
		std::string object = see.substr(0, see.find(","));
		object = replaceinString(object, " ", "");
		if (x < 0)
			arrow = LEFT;
		if (x == 0)
			arrow = FRONT;
		if (x > 0)
			arrow = RIGHT;
		if (object != "")
		{
			if (isObject(object) == true)
			{
				if (range == 0)
					return (ON);
				return (arrow);
			}
		}
		if (x == range)
		{
			range++;
			x = range * -1;
		}
		else
			x++;
		see = see.substr(see.find(",") + 1);
	}
	return (NO);
}

// Recherche d'Object
// void			myIA::searchRock()
// {
// 	// int i = 0;
// 	// Direction see = 0;

// 	// if (_startsearch == NULL)
// 	// 	_startsearch = _pos;
// 	// else if (_startsearch == _pos)
// 	// {
// 	// 	cmdRot(RIGHT);
// 	// 	cmdMove(_range * 2);
// 	// 	cmdRot(LEFT);
// 	// 	_startsearch = _pos;
// 	// }
// 	// while (i++ < 4 && (see = checkRock()) == NO)
// 	// 	cmdRot(RIGHT);
// 	// if (see == NO)
// 	// 	cmdMove(_range * 2);
// 	// else if (see == ON)
// 	// 	cmdTake(chooseRock(_lastsee));
// 	// else if (see == FRONT)
// 	// 	cmdMove(1);
// 	// else
// 	// {
// 	// 	cmdRot(see);
// 	// 	cmdMove(1);
// 	// 	if (see == RIGHT)
// 	// 		cmdRot(LEFT);
// 	// 	else
// 	// 		cmdRot(RIGHT);
// 	// 	cmdMove(1);
// 	// }
// }​


// const std::string	&myIA::sendCommand()
// {
// 	std::string cmd = "";
// 	if (!_send.empty())
// 	{
// 		cmd = _send.front();
// 		_send.pop_front();
// 	}
// 	return (cmd);
// }

// bool				myIA::addCommand(const std::string &cmd)
// {
// 	if (_send.size() < 10)
// 	{
// 		_send.push_back(cmd);
// 		return (true);
// 	}
// 	return (false);
// }

// std::string			&myIA::recieveAwser()
// {
// 	std::string cmd = "";
// 	if (!_recieve.empty())
// 	{
// 		cmd = _recieve.front();
// 		_recieve.pop_front();
// 	}
// 	return (cmd);
// }

// void				myIA::addRecieveAwser(std::string &cmdR)
// {
// 	_recieve.push_back(cmdR);
// }

// // void				myIA::addRock(Object obj)
// // {
// // 	_listRock.push_back(obj);
// // }

// // void				myIA::delRock(Object obj)
// // {
// // 	_listRock.remove(obj);
// // }

// bool				myIA::isReadyRock()
// {
// 	if (_listRock.empty() == true)
// 		return (true);
// 	return (false);
// }

void				myIA::initTabElevation()
{
	// _tabElevation.push_back((int[]){ 1, 1, 0, 0, 0, 0, 0 });
	// _tabElevation.push_back((int[]){ 2, 1, 1, 1, 0, 0, 0 });
	// _tabElevation.push_back((int[]){ 2, 2, 0, 1, 0, 2, 0 });
	// _tabElevation.push_back((int[]){ 4, 1, 1, 2, 0, 1, 0 });
	// _tabElevation.push_back((int[]){ 4, 1, 2, 1, 3, 0, 0 });
	// _tabElevation.push_back((int[]){ 6, 1, 2, 3, 0, 1, 0 });
	// _tabElevation.push_back((int[]){ 6, 2, 2, 2, 2, 2, 1 });
}