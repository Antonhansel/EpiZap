#ifndef MYIA_HPP
# define MYIA_HPP

# include <iostream>
# include <list>
# include <vector>
# include <map>

enum Object
{
	FOOD,
	PLAYERS,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
};

enum Direction
{
	ON,
	NO,
	FRONT,
	RIGHT,
	LEFT
};

class myIA
{
public:
	std::list<std::string> 			_recieve;
	std::list<std::string> 			_send;
	std::vector<std::string>		_listRock;
	std::vector<Object>				_objectifs;
	std::vector<int[7]>				_tabElevation;
	unsigned int 					_sizeQueue;
	unsigned int 					_range;

public:
	myIA();
	~myIA();
	// bool				initLoop();
	void				initTabElevation();
	void				initRock();

	// const std::string	&sendCommand();
	// bool				addCommand(const std::string &);
	// std::string			&recieveAwser();
	// void				addRecieveAwser(std::string &);

	// void				addRock(Object);
	// void				delRock(Object);

	bool				isReadyRock();
	bool				isObject(std::string &);

	Direction			checkRock(std::string &);
	// void				searchRock();
	std::string 		&replaceinString(std::string &, const std::string &, const std::string &);
};

#endif /* !MYIA_HPP */