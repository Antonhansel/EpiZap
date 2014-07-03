#include "Server.h"
#include "List.h"
#include "CircularBuffer.h"
#include "start_functions.h"

int 		init_bits_fields(Server *this, fd_set *readfds, fd_set *writefds)
{
	Player 	*tmp;

	tmp = this->player;
	FD_ZERO(readfds);
	FD_ZERO(writefds);
	FD_SET(this->socket, readfds);
	while (tmp != NULL)
	{
		if (tmp->mode == WRITE)
			FD_SET(tmp->fd, writefds);
		else
			FD_SET(tmp->fd, readfds);
		tmp = tmp->next;
	}
	return (0);
}

int 		check_bits_fields(Server *this, fd_set *readfds, fd_set *writefds)
{
	Player 	*tmp;

	tmp = this->player;
	printf("check bits fields\n");
	while (tmp != NULL)
	{
		if (FD_ISSET(tmp->fd, writefds))
			fct_write(tmp, this);
		else
		{
			if (FD_ISSET(tmp->fd, readfds))
			{
				fct_read(tmp, this);
				if (tmp->intro == TRUE)
					assign_to_team(tmp, this);
			}
		}
		tmp = tmp->next;
	}
	return (0);
}

int						accept_socket(Server *s)
{
	struct sockaddr_in  client_sin; 
	socklen_t 			len;
	int 				fd;

	len = sizeof(client_sin);
	if ((fd = xaccept(s->socket, &(client_sin), &len)) == FALSE)
		return (FALSE);
	printf("----------- AVANT ADD ----------\n");
	display_list(s->player);
	if (add_elem(&s->player, fd, s->map->width, s->map->height) != 0)
		return (FALSE);
	else
		sprintf(s->msg,
			"<font color=\"Green\">*** CLIENT ADD IN LIST ***</font><br />");
	printf("----------- APRES ADD ----------\n");
	display_list(s->player);
	if (s->max_fd < fd)
		s->max_fd = fd;
	s->nb_player_co++;
	printf("-----> MAX FD = %d\n", s->max_fd);
	sprintf(s->msg,
		"%s<font color=\"Green\">*** NEW CONNECTION FROM IP %s ON PORT %d AND FD %d ***</font>", s->msg, inet_ntoa(client_sin.sin_addr), s->port, fd);
	return (TRUE);
}
