#include "../header/myIA.hpp"

myIA::myIA() 
{
	_isAlive = true;
	_range = 1;
	_startsearch = 0;
	_dim = std::make_pair(10, 10);
}

myIA::~myIA() {}

void	myIA::initThread()
{
	Network  *net = new Network(_receive, _send, "10.12.181.101", 4242, "Team10\n");
	QThread   *q = new QThread();
	net->moveToThread(q);
	connect(q, SIGNAL(started()), net, SLOT(doWork()));
	q->start();
}

bool				myIA::initLoop()
{
	std::ostringstream convert;


	initThread();
//	while (true);;
	initObjects();
	initTabElevation();
	while (_isAlive == true && _range < 8)
	{
		initObjectifs();
		
		/* ### TEST Objectifs ### */
		displayObjectifs();
		
		while (_objectifs.size() > 2)
		{
			searchRock();
		}
		/* ###  POUR TESTER ON INCREMENTE RANGE MANUELLEMENT ### */
		_range++;

		// if (_broadcast == true)
		// {
		// 	convert << _range;
		// 	cmdBroadcast("broadcast [answer][" + convert.str() + "]\n");
		// 	moveToward();
		// 	incantation();
		// }
		// else
		// {
		// 	convert << _range;
		// 	cmdBroadcast("broadcast [call][" + convert.str() + "]\n");
		// 	while (_broadcast != true)
		// 	{
		// 		searchRock();
		// 	}
		// 	draw();
		// }
	}
	return (true);
}

void				myIA::displayObjectifs()
{
	unsigned int 	x = 0;

	std::cout << "Objectifs:" << std::endl;
	while (x < _objectifs.size())
		std::cout << _objectifs[x++] << std::endl;
}

void			myIA::initObjectifs()
{
	int 				x = _objects.size() - 2;

	_objectifs.push_back("food");
	while (x >= 0)
	{
		int 	i = _tabElevation[_range - 1][x];
		if (i > 0)
		{
			_objectifs.push_back(_objects[x]);
			_tabElevation[_range - 1][x] -= 1;
		}
		else if (i == 0)
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

bool				myIA::isObjectif(std::string &object)
{
	unsigned int 	x = 0;

	while (x < _objectifs.size())
		if (object.compare(_objectifs[x++]) == 0)
			return (true);
	return (false);
}

std::string 	&myIA::replaceinString(std::string &str, const std::string &toFind, const std::string &toReplace)
{
	size_t pos = 0;
	for (pos = str.find(toFind); pos != std::string::npos; pos = str.find(toFind, pos))
		str.replace(pos, 1, toReplace);
	return(str);
}

Direction			myIA::checkRock()
{
	std::cout << "Envoie command SEE" << std::endl;
	std::string		see = cmdSee();
	std::cout << "Recus:\n" << see << std::endl;
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
		else if (x == 0)
			arrow = FRONT;
		else
			arrow = RIGHT;
		if (!object.empty() && isObjectif(object) == true)
		{
			if (range == 0)
			{
				_saveObj = object;
				return (ON);
			}
			else
			{
				_saveObj = "";
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
	Direction 	see = NO;
	std::string food = "food";

	if ((_startsearch >= _dim.first && _dir == 1) || (_startsearch >= _dim.second && _dir == -1))
	{
		_startsearch = 0;
		cmdRot(RIGHT);
		cmdMove(_range * 2);
		cmdRot(LEFT);
	}
	for (int i = 0; i < 4 && (see = checkRock()) == NO; i++)
		cmdRot(RIGHT);
	if (see == NO)
		cmdMove(_range * 2);
	else if (see == ON)
	{
		/* ### FOR TESTING ### */
		std::cout << "We are taking " << _saveObj << std::endl;
		cmdTake(_saveObj);
	}
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
}

void				myIA::initTabElevation()
{
	int level1[7] = { 1, 1, 0, 0, 0, 0, 0 };
	int level2[7] = { 2, 1, 1, 1, 0, 0, 0 };
	int level3[7] = { 2, 2, 0, 1, 0, 2, 0 };
	int level4[7] = { 4, 1, 1, 2, 0, 1, 0 };
	int level5[7] = { 4, 1, 2, 1, 3, 0, 0 };
	int level6[7] = { 6, 1, 2, 3, 0, 1, 0 };
	int level7[7] = { 6, 2, 2, 2, 2, 2, 1 };

	std::vector<int> tabLevel1(level1, level1 + 7);
	std::vector<int> tabLevel2(level2, level2 + 7);
	std::vector<int> tabLevel3(level3, level3 + 7);
	std::vector<int> tabLevel4(level4, level4 + 7);
	std::vector<int> tabLevel5(level5, level5 + 7);
	std::vector<int> tabLevel6(level6, level6 + 7);
	std::vector<int> tabLevel7(level7, level7 + 7);

	_tabElevation.push_back(tabLevel1);
	_tabElevation.push_back(tabLevel2);
	_tabElevation.push_back(tabLevel3);
	_tabElevation.push_back(tabLevel4);
	_tabElevation.push_back(tabLevel5);
	_tabElevation.push_back(tabLevel6);
	_tabElevation.push_back(tabLevel7);
}

/*
bool 			myIA::moveToward()
{
	std::ostringstream convert;
	int 		direction = 1;
	int 		pos = 1;

	while (pos != 0)
	{
		convert << _range;
		std::string answer = cmdBroadcast("[broadcast][okay][" + convert.str() + "]");
		pos = _k;

		if (pos != 0)
		{
			while (direction != pos / 2)
			{
				cmdRot(LEFT);
				direction++;
			}
			cmdMove(1);
		}
		convert << _range;
		cmdBroadcast("[broadcast][start][" + convert.str() + "]");
	}
	return (true);
}

bool 			myIA::draw()
{
	int 		pos = 1;
//int 		direction = 1;
	std::ostringstream convert;

	while (pos != 0)
	{
		convert << _range;
		std::string answer = cmdBroadcast("[broadcast][come][" + convert.str() + "]");
		if (answer.compare("okay"))
			pos = _level;
	}
	return (true);
}
*/