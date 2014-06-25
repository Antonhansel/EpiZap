/*
** list.c for list.c in /home/david_c/B4/unixSystem/my_irc/server/src
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Mon Apr 14 14:07:13 2014 DAVID Flavien
** Last update Tue Apr 22 10:52:11 2014 DAVID Flavien
*/

#include "server.h"
#include "handle.h"
#include "list.h"

int	add_elem(t_fd **front_ptr, int fd,
			 char *addr, char *name)
{
  t_fd	*node;
  t_fd	*tmp;

  node = malloc(sizeof(t_fd));
  if (node == NULL)
    return (-1);
  node->nickname = strdup(name);
  node->addr = strdup(addr);
  node->fd = fd;
  node->channel = strdup("home");
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

int	del_elem(t_fd **front_ptr, char *name)
{
  t_fd	*tmp;
  t_fd	*tmp_prev;

  if (*front_ptr == NULL)
    return (-1);
  if (strcmp((*front_ptr)->nickname, name) == 0)
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
      if (strcmp(tmp->nickname, name) == 0)
	{
	  tmp_prev->next = tmp->next;
	  free(tmp);
	}
      tmp_prev = tmp;
      tmp = tmp->next;
    }
  return (0);
}

int	get_max_fd(t_fd *front_ptr)
{
  t_fd	*tmp;
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

void	init_fd(t_fd *front_ptr, fd_set *readfds)
{
  t_fd	*tmp;

  tmp = front_ptr;
  while (tmp != NULL)
    {
      FD_SET(tmp->fd, readfds);
      tmp = tmp->next;
    }
}

int	check_fd(t_fd **front_ptr, fd_set *readfds)
{
  t_fd	*tmp;

  tmp = *front_ptr;
  while (tmp != NULL)
    {
      if (FD_ISSET(tmp->fd, readfds))
	{
	  handle_client(front_ptr, tmp);
	  return (0);
	}
      tmp = tmp->next;
    }
  return (0);
}
