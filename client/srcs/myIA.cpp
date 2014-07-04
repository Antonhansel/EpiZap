myIA::myIA() 
{
	_sizeQ = 0;
}

myIA::~myIA() {}

bool				myIA::initLoop()
{
	bool			isAlive = true;
	Command 		lastCmd;
	std::string		anwser;

	initTabElevation();
	while (isAlive == true)
	{
		fillObjectifs();

		while (_objectifs.size() > 1)
		{
			searchRock();
		}

		// BROADCAST TODO

	}
}

void			myIA::initRock()
{
	_listRock[LINEMATE] = "linemate";
	_listRock[DERAUMERE] = "deraumere";
	_listRock[SIBUR] = "sibur";
	_listRock[MENDIANE] = "mendiane";
	_listRock[PHIRAS] = "phiras";
	_listRock[THYSTAME] = "thystame";
	_listRock[FOOD] = "food";
}

// return TRUE si on a besoin de cet Object ou return FALSE
bool				myIA::isObject(std::string &object)
{
	int 	x = 1;
	std::string	food = "food";

	while (x < FOOD)
	{
		if (object.compare(_listRock[x]) == 0 ||
			food.compare(_listRock[x]) == 0)
		{
			return (true);
		}
		x++;
	}
	return (false);
}

// remplace tout les espaces par 0
std::string 	&myIa::replaceinString(std::string str, std::string toFind, std::string toReplace)
{
	size_t pos = 0;
	for (pos = str.find(toRind); pos != std::string::npos; pos = str.find(toFind, pos))
	{
		str.replace(pos, 1, toReplace);
	}
	return(str);
}

// return ON si Object rechercher est a nos pied ou devant nous
// return RIGHT si Object rechercher est a droitre
// return LEFT si Object rechercher est a guauche
// return NO si Object rechercher n'a pas était trouvé
Direction			myIA::checkRock()
{
	std::string		see = cmdSee();
	int 			pos = 0;
	int 			pos2 = 0;
	Direction		arrow = FRONT;

	while (see != "")
	{
		std::string object = see.substr(0, see.find(","));
		object = replaceinString(object, " ", "");
		if (pos2 < 0)
			arrow = LEFT;
		if (pos2 == 0)
			arrow = FRONT;
		if (pos2 < 0)
			arrow = RIGHT;
		if (object != "")
		{
			if (isObject(rock) == true)
			{
				if (pos == 0)
					return (ON)
				return (arrow);
			}
		}
		if (pos2 == pos)
		{
			pos++;
			pos2 = pos * -1 - 1;
		}
		pos2++;
		str = str.substr(str.find(",") + 1);
	}
	return (NO);
}

// Recherche d'Object
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


const std::string	&myIA::sendCommand()
{
	if (!send.isEmpty())
	{
		std::string cmd = send.front();
		send.pop_front();
		return (cmd);
	}
}

bool				myIA::addCommand(const std::string &cmd)
{
	if (send.size() < 10)
	{
		send.push_back(cmd);
		return (true);
	}
	return (false);
}

std::string			&myIA::recieveAwser()
{
	if (!recieve.isEmpty())
	{
		std::string cmd;
		cmd = recieve.front();
		recieve.pop_front();
		return (cmd);
	}
}

void				myIA::addRecieveAwser(std::string &cmdR)
{
	recieve.push_back(cmdR);
}

void				myIA::addRock(Object) obj)
{
	listRock.push_back(obj);
}

void				myIA::delRock(Object obj)
{
	listRock.remove(obj);
}

bool				myIA::isReadyRock()
{
	if (listRock.isEmpty() == true)
		return (true);
	return (false);
}

void				myIA::initTabElevation()
{
	_tabElevation[1] = {1, 1, 0, 0, 0, 0, 0};
	_tabElevation[2] = {2, 1, 1, 1, 0, 0, 0};
	_tabElevation[3] = {2, 2, 0, 1, 0, 2, 0};
	_tabElevation[4] = {4, 1, 1, 2, 0, 1, 0};
	_tabElevation[5] = {4, 1, 2, 1, 3, 0, 0};
	_tabElevation[6] = {6, 1, 2, 3, 0, 1, 0};
	_tabElevation[7] = {6, 2, 2, 2, 2, 2, 1};
}