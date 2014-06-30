#include "List.h"
#include "Server.h"

int	add_elem(Player **front_ptr, int fd)
{
  Player	*node;
  Player	*tmp;

  node = malloc(sizeof(Player));
  if (node == NULL)
    return (-1);
  init_player(node, fd);
  node->next = NULL;
  tmp = *front_ptr;
  if (tmp == NULL)
    *front_ptr = node;
  else
  {
    while (tmp->next != NULL)
      tmp = tmp->next;
    tmp->next = node;
  }
  return (0);
}

int	del_elem(Player **front_ptr, int fd)
{
  Player	*tmp;
  Player	*tmp_prev;

  if (*front_ptr == NULL)
    return (-1);
  if ((*front_ptr)->fd == fd)
  {
    tmp = *front_ptr;
    *front_ptr = tmp->next;
    free(tmp);
    return (0);
  }
  tmp = (*front_ptr)->next;
  tmp_prev = *front_ptr;
  while (tmp_prev != NULL && tmp != NULL)
  {
    if (tmp->fd == fd)
    {
      tmp_prev->next = tmp->next;
      free(tmp);
    }
    tmp_prev = tmp;
    tmp = tmp->next;
  }
  return (0);
}

int	get_max_fd(Player *front_ptr)
{
  Player	*tmp;
  int	max;

  tmp = front_ptr;
  max = 0;
  while (tmp != NULL)
  {
    if (tmp->fd > max)
      max = tmp->fd;
    tmp = tmp->next;
  }
  return (max + 1);
}

void	init_fd(Player *front_ptr, fd_set *readfds)
{
  Player	*tmp;

  tmp = front_ptr;
  while (tmp != NULL)
  {
    FD_SET(tmp->fd, readfds);
    tmp = tmp->next;
  }
}

int	check_fd(Player **front_ptr, Server *server, fd_set *readfds)
{
  Player	*tmp;

  tmp = *front_ptr;
  while (tmp != NULL)
  {
    if (FD_ISSET(tmp->fd, readfds))
    {
      tmp->fct_read(tmp, server);
//handle_client(front_ptr, tmp);
      return (0);
    }
    tmp = tmp->next;
  }
  return (0);
}
