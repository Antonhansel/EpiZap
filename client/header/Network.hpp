#ifndef NETWORK_HPP_
# define NETWORK_HPP_

# include <QObject>
# include <QDebug>
# include <QThread>
# include <QTimer>
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
# include "CircularBuffer.hh"

int		xconnect(int, struct sockaddr_in *, socklen_t);

class Network : public QObject
{
    Q_OBJECT
public:
    Network(std::list<std::string> &, std::list<std::string> &);
    ~Network();

private:
	bool	initSocket();

public slots:
    void    doWork();

signals:
    void finished();
    void error(QString err);
 
private:
	bool						_run;
	int							_fd;
	int 						_port;
	std::list<std::string> 		_receive;
	std::list<std::string> 		_send;
	CircularBuffer				*_circularBuffer;
};
#endif