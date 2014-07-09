#ifndef MYIA_HPP
# define MYIA_HPP

# include "Command.hpp"

enum Dir
{
	X = 1,
	Y = -1,
};

class myIA : public Command
{
private:
	int 								_startrange;
	std::vector<std::string>			_objects;
	std::vector<std::string>			_objectifs;
	std::vector< std::vector< int > >	_tabElevation;

	bool								_isAlive;
	int 								_x;
	int 								_y;
public:
	myIA();
	~myIA();
	bool				initLoop();
	void				initTabElevation();
	void				initObjects();
	void				initObjectifs();

	bool				moveToward();
	bool 				draw();
	bool				isReadyRock();
	bool				isObject(std::string &);

	Direction			checkRock();
	void				searchRock();
	std::string 		&replaceinString(std::string &, const std::string &, const std::string &);
};

#endif /* !MYIA_HPP */