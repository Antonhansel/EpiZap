#include "../header/myIA.hpp"

myIA::myIA() 
{
	_isAlive = true;
	_range = 1;
}

myIA::~myIA() {}

bool				myIA::initLoop()
{
	initObjects();
	initTabElevation();
	while (_isAlive == true && _cmd.getLevel() < 8)
	{
		initObjectifs();
		_range = _cmd.getLevel();
		while (_objectifs.size() > 2)
		{
			searchRock();
		}

		if (_cmd.getBroadCast() == true)
		{
			_cmd.upBroadCast("up_answer_" + _range);
			moveToward();
		}
		else
		{
			while (_cmd.getBroadCast() != true)
			{
				_cmd.upBroadCast("up_call_" + _range);
				searchRock();
			}
			draw();
		}

	}
	return (true);
}

bool 			myIA::moveToward()
{
	int 		direction = 1;
	int 		pos = 1;

	while (pos != 0)
	{
		std::string answer = _cmd.cmdBroadcast();
		pos = getPos(answer);

		if (pos != 0)
		{
			while (direction != pos)
			{
				_cmd.cmdRot(LEFT);
			}
			_cmd.cmdMove(1);
		}
		else
		{
			_cmd.cmdBroadcast("up_start");
		}
	}
	return (true);
}

bool 			myIA::draw()
{
	int 		pos = 1;
	int 		direction = 1;

	while (pos != 0)
	{
		std::string answer = _cmd.cmdBroadcast();
		pos = getPos(answer);
	}
	return (true);
}

void			myIA::initObjectifs()
{
	std::vector<int>	currentLevel;
	int 				x = _objects.size() - 2;

	currentLevel = _tabElevation[_range];
	_objectifs.push_back("food");
	while (!currentLevel.empty())
	{
		int 	i = currentLevel.back();
		if (i > 0)
			_objectifs.push_back(_objects[x]);
		currentLevel.pop_back();
		x--;
	}
}

void			myIA::initObjects()
{
	_objects.push_back("player");
	_objects.push_back("linemate");
	_objects.push_back("deraumere");
	_objects.push_back("sibur");
	_objects.push_back("mendiane");
	_objects.push_back("phiras");
	_objects.push_back("thystame");
	_objects.push_back("food");
}

bool				myIA::isObject(std::string &object)
{
	int 	x = 0;

	while (x < _objectifs.size())
	{
		if (object.compare(_objectifs[x]) == 0)
		{
			return (true);
		}
		x++;
	}
	return (false);
}

std::string 	&myIA::replaceinString(std::string &str, const std::string &toFind, const std::string &toReplace)
{
	size_t pos = 0;
	for (pos = str.find(toFind); pos != std::string::npos; pos = str.find(toFind, pos))
	{
		str.replace(pos, 1, toReplace);
	}
	return(str);
}

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

void			myIA::searchRock()
{
	int i = 0;
	Direction see = 0;

	if (_startsearch == NULL)
		_startsearch = _pos;
	else if (_startsearch == _pos)
	{
		cmdRot(RIGHT);
		cmdMove(_range * 2);
		cmdRot(LEFT);
		_startsearch = _pos;
	}
	while (i++ < 4 && (see = checkRock()) == NO)
		cmdRot(RIGHT);
	if (see == NO)
		cmdMove(_range * 2);
	else if (see == ON)
		cmdTake(chooseRock(_lastsee));
	else if (see == FRONT)
		cmdMove(1);
	else
	{
		cmdRot(see);
		cmdMove(1);
		if (see == RIGHT)
			cmdRot(LEFT);
		else
			cmdRot(RIGHT);
		cmdMove(1);
	}
}​


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
	int level1[7] = { 1, 1, 0, 0, 0, 0, 0 };
	std::vector<int> tabLevel1(level1, level1 + 7);
	int level2[7] = { 2, 1, 1, 1, 0, 0, 0 };
	std::vector<int> tabLevel2(level1, level1 + 7);
	int level3[7] = { 2, 2, 0, 1, 0, 2, 0 };
	std::vector<int> tabLevel3(level1, level1 + 7);
	int level4[7] = { 4, 1, 1, 2, 0, 1, 0 };
	std::vector<int> tabLevel4(level1, level1 + 7);
	int level5[7] = { 4, 1, 2, 1, 3, 0, 0 };
	std::vector<int> tabLevel5(level1, level1 + 7);
	int level6[7] = { 6, 1, 2, 3, 0, 1, 0 };
	std::vector<int> tabLevel6(level1, level1 + 7);
	int level7[7] = { 6, 2, 2, 2, 2, 2, 1 };
	std::vector<int> tabLevel7(level1, level1 + 7);
	_tabElevation.push_back(tabLevel1);
	_tabElevation.push_back(tabLevel2);
	_tabElevation.push_back(tabLevel3);
	_tabElevation.push_back(tabLevel4);
	_tabElevation.push_back(tabLevel5);
	_tabElevation.push_back(tabLevel6);
	_tabElevation.push_back(tabLevel7);
}