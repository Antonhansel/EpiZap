#ifndef MYIA_HPP
# define MYIA_HPP

enum Rock
{
	PLAYERS,
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME
};

class myIA
{
private:
	std::list<std::string> 		_receive;
	std::list<std::string> 		_send;


	std::list<Rock>				_listRock;
	std::map<pair<int, int[]>>	_tabElevation;

public:
	myIA();
	~myIA();
	const std::string	&sendCommand();
	bool				addCommand(const std::string &);
	std::string			&recieveAwser();
	void				addRecieveAwser(std::string &);
	void				addRock(Rock);
	void				delRock(Rock);
	bool				isReadyRock();
	bool				initLoop();
	void				initTabElevation();
};

#endif /* !MYIA_HPP */