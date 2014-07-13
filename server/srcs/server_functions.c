/*
** server_functions.c for server_functions.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:03:40 2014 Flavien David
** Last update sam. juil.  12 18:03:40 2014 Flavien David
*/

#include "Server.h"
#include "List.h"
#include "CircularBuffer.h"
#include "start_functions.h"

int		init_bits_fields(t_server *this, fd_set *rfds, fd_set *wfds)
{
  t_player	*tmp;

  tmp = this->player;
  FD_ZERO(rfds);
  FD_ZERO(wfds);
  FD_SET(this->socket, rfds);
  while (tmp != NULL)
    {
      if (tmp->mode == WRITE)
	FD_SET(tmp->fd, wfds);
      else
	FD_SET(tmp->fd, rfds);
      tmp = tmp->next;
    }
  return (0);
}

int		check_bits_fields(t_server *this, fd_set *rfds, fd_set *wfds)
{
  t_player	*tmp;

  tmp = this->player;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, wfds))
	fct_write(tmp, this);
      else
	{
	  if (FD_ISSET(tmp->fd, rfds))
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
	   "%s<font color=\"Green\">** CONNECTION FROM IP %s, FD %d **</font>",
	   s->msg, inet_ntoa(client_sin.sin_addr), fd);
  return (TRUE);
}
