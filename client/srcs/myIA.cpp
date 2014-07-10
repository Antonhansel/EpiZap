#include "../header/myIA.hpp"

myIA::myIA() 
{
	_isAlive = true;
	_range = 1;
	_startrange = 0;
	_dir = 1;
	_x = 10;
	_y = 10;
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
	while (true);;
/*	initObjects();
	initTabElevation();
	while (_isAlive == true && (_range = _level) < 8)
	{
_isAlive = false;  -------------------------------------------------------- */
		/*initObjectifs();
while (_objectifs.size() > 2)
{
searchRock();
}

if (_broadcast == true)
{
convert << _range;
cmdBroadcast("[broadcast][answer][" + convert.str() + "]");
moveToward();
}
else
{
convert << _range;
cmdBroadcast("[broadcast][call][" + convert.str() + "]");
while (_broadcast != true)
{
searchRock();
}
draw();
}
}*/
return (true);
}

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
	unsigned int 	x = 0;

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

Direction			myIA::checkRock()
{
	std::string		see = cmdSee();
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
/*int 		i = 0;
Direction 	see = NO;
std::string food = "food";

if (_startrange >= _x && _dir == X || _startrange >= _y && _dir == Y)
{
cmdRot(RIGHT);
cmdMove(_range * 2);
cmdRot(LEFT);
_startrange = 0;
}
while (i++ < 4 && (see = checkRock()) == NO)
cmdRot(RIGHT);
if (see == NO)
cmdMove(_range * 2);
else if (see == ON)
{
cmdTake(food);
_startrange = 0;
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
}*/
}

void				myIA::initTabElevation()
{
/*	int level1[7] = { 1, 1, 0, 0, 0, 0, 0 };
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
_tabElevation.push_back(tabLevel7);*/
}