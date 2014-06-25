#include "Server.h"
#include "checkFd.h"

static int		accept_socket(Server *);

char 		*server_init(Server *this)
{
	int 	opt;

	opt = 1;
	this->clients = NULL;
	this->accept_socket = &accept_socket;
	this->init_fd = &init_fd;
	this->check_fd = &check_fd;
	if ((this->pe = getprotobyname("TCP")) == NULL)
		return ("<font color=\"Red\">*** ERROR ON GETPROTOBYNAME ***</font>");
	if ((this->socket = xsocket(AF_INET, SOCK_STREAM, this->pe->p_proto)) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON CREATE SOCKET ***</font>");
	this->sin.sin_family = AF_INET;
	this->sin.sin_port = htons(this->port);
	this->sin.sin_addr.s_addr = INADDR_ANY;
	setsockopt(this->socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if ((xbind(this->socket, &this->sin, sizeof(this->sin))) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON BIND ***</font>");
	xlisten(this->socket, 10);
	this->initialize = TRUE;
	this->maxFd = this->socket;
    memset(((void*)(this->msg)), 0, 256);
	return ("<font color=\"Green\">*** SUCCESSLY INIT ***</font>");
}

static int	accept_socket(Server *s)
{
	int len = sizeof(s->sin);
	int fd = xaccept(s->socket, &(s->sin), (socklen_t *)&len);
	if (s->clients == NULL)
	{
		s->clients = malloc(sizeof(void) * 100);
		s->clients = memset(s->clients, 0, 100);
	}
	Client *c;
	if ((c = malloc(sizeof(Client))) == NULL)
		return (-1);
	createClient(c, fd);
	s->clients[fd] = c;
	if (s->maxFd < fd)
		s->maxFd = fd;
	sprintf(s->msg, "<font color=\"Green\">*** NEW CONNECTION FROM IP %s ON PORT %d AND FD %d ***</font>", "NO IP", s->port, fd);
	if (write(fd, "--- SUCCESSLY CONNECT ---\n", 26) <= 0)
		return (1);
	return (0);
}

int 				server_loop(Server *this)
{
	int 			error;
	int 			result;
	int 			resultPrev;
	fd_set 			readfds;
	struct timeval	tv;

	tv.tv_usec = 100;
	tv.tv_sec = 0;
	error = 0;
	result = 0;
	resultPrev = 0;
	while (!error)
	{
		FD_ZERO(&readfds);
		FD_SET(this->socket, &readfds);
		if ((result = select(this->maxFd + 1, &readfds, NULL, NULL, &tv)) == -1)
			return (1);
		else if (FD_ISSET(this->socket, &readfds))
			(*this->accept_socket)(this);
		else if (result != resultPrev)
		{
			(*this->check_fd)(this, &readfds);
			resultPrev = result;
		}
	}
	return (0);
}