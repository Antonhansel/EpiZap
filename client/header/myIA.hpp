#ifndef MYIA_HPP
# define MYIA_HPP

# include <QWidget>
# include <QObject>
# include <QApplication>
# include "Command.hpp"
# include "Network.hpp"

enum Dir
{
	X = 1,
	Y = -1,
};

class myIA : public QObject, public Command
{
    Q_OBJECT
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
	void				initThread();
	bool				moveToward();
	bool 				draw();
	bool				isReadyRock();
	bool				isObject(std::string &);
	Direction			checkRock();
	void				searchRock();
	std::string 		&replaceinString(std::string &, const std::string &, const std::string &);
};

#endif /* !MYIA_HPP */