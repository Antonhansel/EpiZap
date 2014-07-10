#ifndef MYIA_HPP
# define MYIA_HPP

# include "Command.hpp"

class myIA : public Command
{
private:
	std::vector<std::string>			_objects;
	std::vector<std::string>			_objectifs;
	std::vector< std::vector< int > >	_tabElevation;
	bool								_isAlive;
	std::pair<int, int>					_dim;
	int 								_startsearch;
	std::string 						_saveObj;
public:
	myIA();
	~myIA();
	bool				initLoop();
	void				initTabElevation();
	void				initObjects();
	void				initObjectifs();

	// bool				moveToward();
	// bool				incantation();
	// bool 				draw();
	// bool				isReadyRock();

	bool				isInObjectifs(std::string &);
	std::string 		&replaceinString(std::string &, const std::string &, const std::string &);
	Direction			checkRock();
	void				searchRock();
	std::vector< std::vector< int > >	getTabElevation() const;

	void				displayObjectifs();

};

#endif /* !MYIA_HPP */