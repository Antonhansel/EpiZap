myIA::myIA() {}

myIA::~myIA() {}

bool				myIA::initLoop()
{
	bool			isAlive = true;
	std::string		anwser;

	initTabElevation();

	while (isAlive == true)
	{
		anwser = recieveAwser();

		if (anwser != "")
		{

		}
		else
		{

		}
	}
}

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

void				myIA::addRock(Rock rock)
{
	listRock.push_back(rock);
}

void				myIA::delRock(Rock rock)
{
	listRock.remove(rock);
}

bool				myIA::isReadyRock()
{
	if (listRock.isEmpty() == true)
		return (true);
	return (false);
}

void				myIA::initTabElevation()
{
	tabElevation.insert(std::pair<int, int[](0, {1, 1, 0, 0, 0, 0, 0}));
	tabElevation.insert(std::pair<int, int[](1, {2, 1, 1, 1, 0, 0, 0}));
	tabElevation.insert(std::pair<int, int[](2, {2, 2, 0, 1, 0, 2, 0}));
	tabElevation.insert(std::pair<int, int[](3, {4, 1, 1, 2, 0, 1, 0}));
	tabElevation.insert(std::pair<int, int[](4, {4, 1, 2, 1, 3, 0, 0}));
	tabElevation.insert(std::pair<int, int[](5, {6, 1, 2, 3, 0, 1, 0}));
	tabElevation.insert(std::pair<int, int[](6, {6, 2, 2, 2, 2, 2, 1}));
}