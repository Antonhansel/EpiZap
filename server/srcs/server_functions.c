#include "Server.h"
#include "List.h"
#include "CircularBuffer.h"	

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
	while (tmp != NULL)
	{
		if (tmp->mode == WRITE)
		{
			if (FD_ISSET(tmp->fd, writefds))
				fct_write(tmp, this);			
		}
		else
		{
			if (FD_ISSET(tmp->fd, readfds))
				fct_read(tmp, this);
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
	if (add_elem(&s->player, fd) != 0)
		return (FALSE);
	else
		sprintf(s->msg, "<font color=\"Green\">*** CLIENT ADD IN LIST ***</font><br />");
	printf("----------- APRES ADD ----------\n");
	display_list(s->player);
	if (s->max_fd < fd)
		s->max_fd = fd;
	s->n_client++;
	printf("-----> MAX FD = %d\n", s->max_fd);
	sprintf(s->msg, "%s<font color=\"Green\">*** NEW CONNECTION FROM IP %s ON PORT %d AND FD %d ***</font>", s->msg, inet_ntoa(client_sin.sin_addr), s->port, fd);
	return (TRUE);
}
