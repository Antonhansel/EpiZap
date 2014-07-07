#ifndef COMMAND_HPP
# define COMMAND_HPP

class Command
{
private:
	std::list<std::string> 		_recieve;
	std::list<std::string> 		_send;
	int							_ignore;
	bool						_broadcast;

public:
	Command();
	~Command();
	void			cmdMove();
	void			cmdRot(Direction);
	std::string		cmdSee();
	bool			cmdTake(std::string);
};

#endif /* !COMMAND_HPP */