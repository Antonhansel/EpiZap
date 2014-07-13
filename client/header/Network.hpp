#ifndef NETWORK_HPP_
# define NETWORK_HPP_

# include <sys/types.h>
# include <stdlib.h>
# include <netdb.h>
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/mman.h>
# include <unistd.h>

enum Mode
{
	WRITE,
	READ
};

enum Action
{
	SEND,
	NOT_SEND
};

int		xconnect(int, struct sockaddr_in *, socklen_t);

class Network
{
public:
    Network(const std::string &, int);
    ~Network();
    bool	getRunState() const;
	int 	getFd() const;
	void	setAction(Action);
	Action 	getAction() const;
	void	addStringToBuf(const std::string &);	
	bool	initSocket();
	void	checkBitsField(fd_set *, fd_set *);
	std::string 	*getReceive() const;
	bool		getIsInit() const;

private:
	bool	fctRead();
	bool	fctWrite();
	bool	socketProblem();

private:
	bool						_run;
	int							_fd;
	std::string					_ipAddr;
	int 						_port;
	Action						_action;
	std::string 				*_receive;
	bool						_isInit;
};
#endif