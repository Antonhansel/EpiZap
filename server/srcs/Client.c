/*
** Client.c for Client.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 16:42:27 2014 jeremie taboada-alvarez
** Last update mer. juin  18 16:42:27 2014 jeremie taboada-alvarez
*/

#include "Client.h"

void		createClient(Client *c, int fd)
{
	c->fd = fd;
	c->nbRequest = 0;
	c->x = 0;
	c->y = 0;
	c->lvl = 1;
	c->next = NULL;
}

int			add_elem(Client **front_ptr, int fd)
{
	Client	*node;
	Client	*tmp;

	node = malloc(sizeof(Client *));
	if (node == NULL)
		return (-1);
	createClient(node, fd);
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

int 		del_elem(Client **front_ptr, int fd)
{
  // Client	*tmp;
  // Client	*tmp_prev;

  // printf("%d\n", fd);
  // if (*front_ptr == NULL)
  //   return (-1);
  // if (fd == (*front_ptr)->fd == 0)
  //   {
  //     tmp = *front_ptr;
  //     *front_ptr = tmp->next;
  //     free(tmp);
  //     return (0);
  //   }
  // tmp = (*front_ptr)->next;
  // tmp_prev = *front_ptr;
  // while (tmp_prev != NULL && tmp != NULL)
  //   {
  //   	if (tmp->fd == fd)
		// {
		//   tmp_prev->next = tmp->next;
		//   free(tmp);
		// }
  //     tmp_prev = tmp;
  //     tmp = tmp->next;
  //   }
  return (0);
}

int 		get_max_fd(Client *front_ptr)
{
	Client	*tmp;
	int 	max;

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

void 		init_fd(t_fd *front_ptr, fd_set *readfds)
{
	t_fd	*tmp;

	tmp = front_ptr;
	while (tmp != NULL)
	{
		FD_SET(tmp->fd, readfds);
		tmp = tmp->next;
	}
}

int 		check_fd(t_fd **front_ptr, fd_set *readfds)
{
	t_fd	*tmp;

	tmp = *front_ptr;
	while (tmp != NULL)
	{
		if (FD_ISSET(tmp->fd, readfds))
		{
		  //handle_client(front_ptr, tmp);
		  return (TRUE);
		}
		tmp = tmp->next;
	}
	return (TRUE);
}

void		display_client(Client *l)
{
	while (l != NULL)
	{
		printf("client fd %d\n", l->fd);
		l = l->next;
	}
}