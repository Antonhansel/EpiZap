#include "List.h"
#include "Server.h"

static void				init_func_ptr(Server *);

static int				accept_socket(Server *);
static int 				loop(Server *);

char 					*server_init(Server *this)
{
	int 				opt;
	struct protoent		*pe;
	struct sockaddr_in	sin;

	opt = 1;
	this->player = NULL;
	init_func_ptr(this);
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

static void			init_func_ptr(Server *this)
{
	this->accept_socket = &accept_socket;
	this->loop = &loop;
}

static int					accept_socket(Server *s)
{
	struct sockaddr_in  	client_sin; 
	socklen_t 				len;
	int 					fd;

	len = sizeof(client_sin);
	if ((fd = xaccept(s->socket, &(client_sin), &len)) == FALSE)
		return (-1);
	
	if (add_elem(&s->player, fd) != 0)
		return (-1);
	else
		sprintf(s->msg, "<font color=\"Green\">*** CLIENT ADD IN LIST ***</font><br />");
	
	if (s->max_fd < fd)
		s->max_fd = fd;
		s->n_client++;
	
	sprintf(s->msg, "%s<font color=\"Green\">*** NEW CONNECTION FROM IP %s ON PORT %d AND FD %d ***</font>", s->msg, inet_ntoa(client_sin.sin_addr), s->port, fd);
	
	if (write(fd, "--- SUCCESSLY CONNECT ---\n", 26) <= 0)
		return (-1);
	
	return (0);
}

static int 			loop(Server *this)
{
	int 			error;
	int 			result;
	//int 			resultPrev;
	fd_set 			readfds;
	struct timeval	tv;

	tv.tv_usec = 100;
	tv.tv_sec = 0;
	error = 0;
	result = 0;
	//resultPrev = 0;
	this->n_client = 0;
	while (!error)
	{
		FD_ZERO(&readfds);
		FD_SET(this->socket, &readfds);
		if ((result = select(this->max_fd + 1, &readfds, NULL, NULL, &tv)) == -1)
			return (1);
		else if (FD_ISSET(this->socket, &readfds))
			(*this->accept_socket)(this);
		/*else if (result != resultPrev)
		{
			(*this->check_fd)(this, &readfds);
			resultPrev = result;
		}*/
	}
	return (0);
}