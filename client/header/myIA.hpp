#ifndef MYIA_HPP
# define MYIA_HPP

# include "Command.hpp"
# include "Network.hpp"

class myIA : public Command
{
private:
	std::vector<std::string>			_objects;
	std::vector<std::string>			_objectifs;
	std::vector< std::vector< int > >	_tabElevation;
	Network								*_net;
	std::string 						_ipAddr;
	std::string 						_teamName;
	int 								_port;
	int 								_socket;

	int 								_startsearch;
	bool								_isAlive;
	std::pair<int, int>					_dim;
	std::string 						_saveObj;
	Mode								_mode;
	bool 								_run;
public:
	myIA();
	~myIA();
	void 				loop();
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

	private:
		bool		initSocket();
		bool		socketProblem();
		bool		fctRead();
		bool		fctWrite();
		void		checkBitsField(fd_set *, fd_set *);
};

#endif /* !MYIA_HPP */