#ifndef COMMAND_HPP
# define COMMAND_HPP

# include <iostream>
# include <string>
# include <list>
# include <stdlib.h>
# include <vector>
# include <map>
# include <unistd.h>
# include <sstream>

enum Object
{
	PLAYERS,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	FOOD
};

enum Direction
{
	ON,
	NO,
	FRONT,
	RIGHT,
	LEFT
};

class Command
{
public:
	std::list<std::string> 		_recieve;
	std::list<std::string> 		_send;
	int							_ignore;
	bool						_broadcast;
	int 						_range;
	int 						_dir;

public:
	std::string					_type;
	std::string					_order;
	int 						_level;
	int 						_k;

public:
	Command();
	~Command();
	void			cmdMove(int );
	void			cmdRot(Direction);
	std::string		cmdSee();
	std::string		cmdBroadcast(const std::string &);
	bool			cmdTake(std::string);
	bool			checkBroadcast(std::string &);
	bool			checkRecieve(std::string);
};

#endif /* !COMMAND_HPP */