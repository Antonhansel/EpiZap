#ifndef MYIA_HPP
# define MYIA_HPP

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

class myIA
{
private:
	std::list<std::string> 		_receive;
	std::list<std::string> 		_send;
	std::list<Object>			_listRock;
	std::vector<Object>			_objectifs;
	std::vector<std::string>	_listRock;
	std::map<int, int[]>		_tabElevation;
	unsigned int 				_sizeQueue;

public:
	myIA();
	~myIA();
	bool				initLoop();
	void				initTabElevation();
	void				initRock();

	const std::string	&sendCommand();
	bool				addCommand(const std::string &);
	std::string			&recieveAwser();
	void				addRecieveAwser(std::string &);

	void				addRock(Object);
	void				delRock(Object);

	bool				isReadyRock();
	bool				isObject(std::string &);

	Direction			checkRock();
	void				searchRock();
	std::string 		&replaceinString(std::string &, std::string &, std::string &)
};

#endif /* !MYIA_HPP */