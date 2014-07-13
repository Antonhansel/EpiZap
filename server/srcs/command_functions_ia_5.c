/*
** command_functions_ia_5.c for command_functions_ia_5.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  dim. juil.  13 10:01:08 2014 Flavien David
** Last update dim. juil.  13 10:01:08 2014 Flavien David
*/

#include "cmd_functions.h"

int calc_long(t_player *p1, t_player *p2, t_server *s)
{
  int i;
  int j;

  i = p2->y - p1->y + s->map->height * s->mi;
  j = p2->x - p1->x + s->map->width * s->mj;
  return (abs(i) + abs(j));
}

int	search(t_player *p1, t_player *p2, void *s)
{
  int	dir;
  int	save;
  int	i;
  int	j;

  i = -2;
  dir = 0;
  p1->mode = WRITE;
  save = ((t_server*)(s))->map->width * ((t_server*)(s))->map->height;
  while (++i < 2)
    {
      j = -2;
      while (++j < 2)
	   if (calc_long(p1, p2, ((t_server*)(s))) < save)
	  {
	    save = calc_long(p1, p2, ((t_server*)(s)));
	    dir = i * 3 + j + 5;
	  }
    }
  return (dir);
}

int calc_angle(t_player *p1, t_player *p2, void *s)
{
  int i;
  int j;

  i = p2->y - p1->y + ((t_server*)(s))->map->height * ((t_server*)(s))->mi;
  j = p2->x - p1->x + ((t_server*)(s))->map->width * ((t_server*)(s))->mj;
  if (abs(i) * 3 <= j && j > 0)
    return (1);
  if (i * 3 >= j && i < j * 3 && i > 0 && j > 0)
    return (2);
  if (i >= abs(j) * 3 && i > 0)
    return (3);
  if (i <= -j * 3 && i * 3 > -j && i > 0 && j < 0)
    return (4);
  if (abs(i) * 3 <= -j && j < 0)
    return (5);
  if (-i * 3 >= -j && -i < -j * 3 && i < 0 && j < 0)
    return (6);
  if (-i >= abs(j) * 3 && i < 0)
    return (7);
  if (-i <= j * 3 && -i * 3 > j && i < 0 && j > 0)
    return (8);
  return (0);
}
