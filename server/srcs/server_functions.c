#include "Server.h"
#include "List.h"
#include "CircularBuffer.h"
#include "start_functions.h"

int		init_bits_fields(t_server *this, fd_set *readfds, fd_set *writefds)
{
  t_player	*tmp;

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

int		check_bits_fields(t_server *this, fd_set *readfds, fd_set *writefds)
{
  t_player	*tmp;

  tmp = this->player;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, writefds))
	fct_write(tmp, this);
      else
	{
	  if (FD_ISSET(tmp->fd, readfds))
	    {
	      if (fct_read(tmp, this) == TRUE && tmp->intro == TRUE)
		assign_to_team(tmp, this);
	    }
	}
      tmp = tmp->next;
    }
  return (0);
}

int			accept_socket(t_server *s)
{
  struct sockaddr_in	client_sin;
  socklen_t		len;
  int			fd;

  len = sizeof(client_sin);
  if ((fd = xaccept(s->socket, &(client_sin), &len)) == FALSE)
    return (FALSE);
  if (add_elem(&s->player, fd) != 0)
    return (FALSE);
  if (s->max_fd < fd)
    s->max_fd = fd;
  s->nb_player_co++;
  snprintf(s->msg, 300,
	   "%s<font color=\"Green\">*** NEW CONNECTION FROM IP %s ON PORT %d AND FD %d ***</font>", s->msg, inet_ntoa(client_sin.sin_addr), s->port, fd);
  return (TRUE);
}
