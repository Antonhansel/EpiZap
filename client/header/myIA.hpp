#ifndef MYIA_HPP
# define MYIA_HPP

# include <QWidget>
# include <QObject>
# include <QApplication>
# include "Command.hpp"
# include "Network.hpp"

class myIA : public QObject, public Command
{
    Q_OBJECT
private:
	std::vector<std::string>			_objects;
	std::vector<std::string>			_objectifs;
	std::vector< std::vector< int > >	_tabElevation;

	int 								_startsearch;
	bool								_isAlive;
	std::pair<int, int>					_dim;
	std::string 						_saveObj;
public:
	myIA();
	~myIA();
	bool				initLoop();
	void				initTabElevation();
	void				initObjects();
	void				initObjectifs();
	void				initThread();
	//bool				moveToward();
	//bool 				draw();
	//bool				isReadyRock();
	bool				isObjectif(std::string &);
	Direction			checkRock();
	void				searchRock();
	std::string 		&replaceinString(std::string &, const std::string &, const std::string &);

	void				displayObjectifs();
	std::vector< std::vector< int > >	getTabElevation() const;
};

#endif /* !MYIA_HPP */