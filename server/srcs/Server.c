#include "List.h"
#include "Server.h"
#include "command_functions.h"

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
	this->accept_socket = &accept_socket;
	this->loop = &loop;
	if ((this->map = malloc(sizeof(Map))) == NULL)
		exit(1);
	init_map(this->map, width, height);
	this->team = NULL;
	this->ptr[AVANCE] = &up_cmd;
	this->ptr[DROITE] = &right_cmd;
	this->ptr[GAUCHE] = &left_cmd;
	this->ptr[VOIR] = &see_cmd;
	this->ptr[INVENTAIRE] = &inventory_cmd;
	this->ptr[PREND_OBJET] = &take_object_cmd;
	this->ptr[POSE_OBJET] = &put_object_cmd;
	this->ptr[EXPULSE] = &kick_cmd;
	this->ptr[BROADCAST_TEXTE] = &broadcast_text_cmd;
	this->ptr[INCANTATION] = &incantation_cmd;
	this->ptr[FORK] = &fork_cmd;
	this->ptr[CONNECT_NBR] = &connect_nbr_cmd;
	strcpy(this->obj[0], "linemate");
	strcpy(this->obj[1], "deraumere");
	strcpy(this->obj[2], "sibur");
	strcpy(this->obj[3], "mendiane");
	strcpy(this->obj[4], "phiras");
	strcpy(this->obj[5], "thystame");
	strcpy(this->obj[6], "food");
}

void init_all_team(Server *this, char *tab)
{
	add_elem_in_team(&this->team, tab, this->nb_player_team);
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