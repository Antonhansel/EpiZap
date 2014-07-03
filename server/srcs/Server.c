#include "List.h"
#include "Server.h"

static void	init_func_ptr(Server *, int, int);
static int 	loop(Server *);
int	 		check_fd(Player **, Server *, fd_set *);

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
	int 		i;

	i = 0;
	this->accept_socket = &accept_socket;
	this->loop = &loop;
	if ((this->map = malloc(sizeof(Map*))) == NULL)
		exit(1);
	init_map(this->map, width, height);
	this->team = NULL;
	while (i < this->nb_teams)
	{
		add_elem_in_team(&this->team, "TOTO", this->nb_player_team);
		//checker return of add_elem_in_team
		++i;
	}
}

static int 		loop(Server *this)
{
	fd_set 		readfds;
	fd_set 		writefds;

	while (TRUE)
	{
		init_bits_fields(this, &readfds, &writefds);
		if (select(this->max_fd + 1, &readfds, &writefds, NULL, NULL) != -1)
		{
			if (FD_ISSET(this->socket, &readfds))
				accept_socket(this);
			check_bits_fields(this, &readfds, &writefds);
		}
		else
			sprintf(this->msg,
				"%s<font color=\"Red\">*** ERROR ON SELECT ***</font>",
					this->msg);
	}
	return (0);
}