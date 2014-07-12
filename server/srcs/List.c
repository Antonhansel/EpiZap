/*
** List.c for List.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:05:40 2014 Flavien David
** Last update sam. juil.  12 18:05:40 2014 Flavien David
*/

#include "List.h"
#include "Server.h"

int		add_elem(t_player **front_ptr, int fd)
{
  t_player	*node;
  t_player	*tmp;

  node = malloc(sizeof(t_player));
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

int		add_square(t_player **front_ptr, t_player *player)
{
  t_player	*tmp;

  tmp = *front_ptr;
  if (tmp == NULL)
    {
      *front_ptr = player;
      player->next_square = NULL;
    }
  else
    {
      while (tmp->next_square)
	tmp = tmp->next_square;
      tmp->next_square = player;
      player->next_square = NULL;
    }
  return (0);
}

int		del_square(t_player **front_ptr, int fd)
{
  t_player	*tmp;
  t_player	*tmp1;

  tmp = *(front_ptr);
  if (tmp && tmp->fd == fd)
  {
    *front_ptr = tmp->next_square;
    return (0);
  }
  while (tmp->next_square)
    {
      if (tmp->next_square->fd == fd)
	{
	  tmp1 = tmp->next_square;
	  tmp->next_square = tmp1->next_square;
	  tmp1->next_square = NULL;
	  return (0);
	}
      tmp = tmp->next_square;
    }
  return (1);
}

int		add_player(t_player **front_ptr, t_player *player)
{
  t_player	*node;
  t_player	*tmp;

  node = malloc(sizeof(t_player));
  if (node == NULL)
    return (-1);
  copy_player(node, player);
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

int		del_elem(t_player **front_ptr, int fd)
{
  t_player	*tmp;

  tmp = *(front_ptr);
  if (tmp && tmp->fd == fd)
    {
      *front_ptr = tmp->next;
      free(tmp);
      return (0);
    }
  while (tmp)
    {
      if (tmp->next && tmp->next->fd == fd)
	{
	  tmp->next = tmp->next->next;
	  return (0);
	}
      tmp = tmp->next;
    }
  return (1);
}
