myIA::myIA() {}

myIA::~myIA() {}

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