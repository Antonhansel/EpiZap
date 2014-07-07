#include "List.h"
#include "Server.h"
#include "command_functions.h"
#include "cmd_functions.h"

static int	init_func_ptr(Server *, int, int);
static int 	loop(Server *);
int	 		check_fd(Player **, Server *, fd_set *);

char 					*init_server(Server *this, int width, int height)
{
	int 				opt;
	struct protoent		*pe;
	struct sockaddr_in	sin;

	opt = 1;
	if (init_func_ptr(this, width, height) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON SERVER INIT ***</font>");
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

static int		init_func_ptr(Server *s, int width, int height)
{
	s->player = NULL;
   	s->team = NULL;
   	s->accept_socket = &accept_socket;
   	s->loop = &loop;
    if ((s->map = malloc(sizeof(Map))) == NULL)
    	return (FALSE);
    s->cmd_list = NULL;
  	init_map(s->map, width, height);
  	init_tab_ptr(s);
  	init_cmd_tab(s);
  	init_time_tab(s);
   	init_obj_tab(s);
  	return (TRUE);
}

void init_all_team(Server *this, char *tab)
{
	add_elem_in_team(&this->team, tab, this->nb_player_team);
}

static int 		loop(Server *this)
{
	fd_set 		readfds;
	fd_set 		writefds;
	int 		timer;

	while (TRUE)
	{
		timer = get_min_time(this->cmd_list, 1000.0);
		init_bits_fields(this, &readfds, &writefds);
		if (select(this->max_fd + 1, &readfds, &writefds, NULL, NULL) != -1)
		{
			if (FD_ISSET(this->socket, &readfds))
				accept_socket(this);
			check_bits_fields(this, &readfds, &writefds);
			set_new_timer(&this->cmd_list, this, timer);
		}
		else
			sprintf(this->msg,
				"%s<font color=\"Red\">*** ERROR ON SELECT ***</font>",
					this->msg);
	}
	return (0);
}