/*
** list.c for list.c in /home/david_c/B4/unixSystem/my_irc/server/src
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Mon Apr 14 14:07:13 2014 DAVID Flavien
** Last update Tue Apr 22 10:52:11 2014 DAVID Flavien
*/

#include "List.h"

void    createClient(Player *c, int fd)
{
  c->fd = fd;
  c->nbRequest = 0;
  c->x = 0;
  c->y = 0;
  c->lvl = 1;
  c->time = 0.0000;
  c->next = NULL;
}

int     add_elem(Player **front_ptr, int fd)
{
  Player  *node;
  Player  *tmp;

  node = malloc(sizeof(Player *));
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

int     del_elem(Player **front_ptr, int fd)
{
  // Client *tmp;
  // Client *tmp_prev;

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
  //    if (tmp->fd == fd)
    // {
    //   tmp_prev->next = tmp->next;
    //   free(tmp);
    // }
  //     tmp_prev = tmp;
  //     tmp = tmp->next;
  //   }
  return (0);
}

int     get_max_fd(Player *front_ptr)
{
  Player  *tmp;
  int   max;

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

void    init_fd(Player *front_ptr, fd_set *readfds)
{
  Player  *tmp;

  tmp = front_ptr;
  while (tmp != NULL)
  {
    FD_SET(tmp->fd, readfds);
    tmp = tmp->next;
  }
}

int     check_fd(Player **front_ptr, fd_set *readfds)
{
  Player  *tmp;

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