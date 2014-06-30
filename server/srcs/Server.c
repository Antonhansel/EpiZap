#include "List.h"
#include "Server.h"

static void		init_func_ptr(Server *, int, int);

static int 		loop(Server *);

int	 check_fd(Player **, Server *, fd_set *);

char 					*init_server(Server *this, int width, int height)
{
	int 				opt;
	struct protoent		*pe;
	struct sockaddr_in	sin;

	opt = 1;
	this->player = NULL;
	init_func_ptr(this, width, height);
	if ((pe = getprotobyname("TCP")) == NULL)
		return ("<font color=\"Red\">*** ERROR ON GETPROTOBYNAME ***</font>");
	if ((this->socket = xsocket(AF_INET, SOCK_STREAM, pe->p_proto)) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON CREATE SOCKET ***</font>");
	sin.sin_family = AF_INET;
	sin.sin_port = htons(this->port);
	sin.sin_addr.s_addr = INADDR_ANY;
	setsockopt(this->socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if ((xbind(this->socket, &sin, sizeof(sin))) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON BIND ***</font>");
	if (xlisten(this->socket, 10) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON LISTEN ***</font>");
	this->initialize = TRUE;
	this->max_fd = this->socket;
    memset(((void*)(this->msg)), 0, 256);
	return ("<font color=\"Green\">*** SUCCESSLY INIT ***</font>");
}

char	*destroy_server(Server *this)
{
	(void)this;
	return ("<font color=\"Green\">*** SUCCESSLY DESTROY ***</font>");
}

static void		init_func_ptr(Server *this, int width, int height)
{
	this->accept_socket = &accept_socket;
	this->loop = &loop;
	if ((this->map = malloc(sizeof(Map*))) == NULL)
		exit(1);
	init_map(this->map, width, height);
}

static int 			loop(Server *this)
{
	int 			result;
	int 			resultPrev;
	fd_set 			readfds;
	fd_set 			writefds;
	struct timeval	tv;

	tv.tv_usec = 100;
	tv.tv_sec = 0;
	result = 0;
	resultPrev = 0;
	this->n_client = 0;
	while (TRUE)
	{
		init_bits_fields(this, &readfds, &writefds);
		if ((result = select(this->max_fd + 1, &readfds, NULL, NULL, &tv)) != -1)
		{
			if (result != resultPrev)
			{
				if (FD_ISSET(this->socket, &readfds))
					accept_socket(this);
				check_fd(&this->player, this, &readfds);
				resultPrev = result;
			}
		}
		else
			sprintf(this->msg, "%s<font color=\"Red\">*** ERROR ON SELECT ***</font>", this->msg);
	}
	return (0);
}