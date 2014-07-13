/*
** command_functions_ia_1.c for command_functions_ia_1.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:06:54 2014 Flavien David
** Last update sam. juil.  12 18:06:54 2014 Flavien David
*/

#include "command_functions.h"
#include "List.h"

void		display_list_square(t_player *);

int		up_cmd(void *serv, t_player *p, char *cmd)
{
  t_server	*s;

  (void)cmd;
  s = ((t_server*)(serv));
  del_square(&s->map->map[p->y][p->x].player, p->fd);
  (p->dir == NORTH) ? p->y-- : (p->dir == EAST) ? p->x++ : (p->dir == WEST) ?
    p->x-- : p->y++;
  if (p->x >= s->map->width)
    p->x = 0;
  else if (p->x < 0)
    p->x = s->map->width - 1;
  if (p->y >= s->map->height)
    p->y = 0;
  else if (p->y < 0)
    p->y = s->map->height - 1;
  add_square(&s->map->map[p->y][p->x].player, p);
  if (p->sent == TRUE)
    {
      add_str_in_buffer(&p->buffer_circular, "ok\n");
      p->mode = WRITE;
    }
  return (0);
}

int	right_cmd(void *s, t_player *p, char *cmd)
{
  (void)s;
  (void)cmd;
  (p->dir == NORTH) ? (p->dir = EAST) : (p->dir == EAST) ? (p->dir = SOUTH) :
    (p->dir == SOUTH) ? (p->dir = WEST) : (p->dir = NORTH);
  add_str_in_buffer(&p->buffer_circular, "ok\n");
  p->mode = WRITE;
  return (0);
}

int	left_cmd(void *s, t_player *p, char *cmd)
{
  (void)s;
  (void)cmd;
  (p->dir == NORTH) ? (p->dir = WEST) : (p->dir == WEST) ? (p->dir = SOUTH) :
    (p->dir == SOUTH) ? (p->dir = EAST) : (p->dir = NORTH);
  add_str_in_buffer(&p->buffer_circular, "ok\n");
  p->mode = WRITE;
  return (0);
}

int	see_cmd(void *s, t_player *p, char *cmd)
{
  int	di;
  int	dj;

  (void)cmd;
  di = 0;
  dj = 0;
  ((t_server*)(s))->player_fd = p->fd;
  (p->dir == NORTH) ? (dj = 1) : (p->dir == SOUTH) ? (dj = -1) :
    (p->dir == WEST) ? (di = -1) : (p->dir == EAST) ? (di = 1) : 0;
  see_loop(s, p, di, dj);
  return (0);
}

int	inventory_cmd(void *s, t_player *p, char *cmd)
{
  char	str1[256];
  char	str[512];

  (void)s;
  (void)cmd;
  snprintf(str1, 256, "{linemate %d, sibur %d, deraumere %d, mendiane %d",
	   p->inventory->get_object(p->inventory, LINEMATE),
	   p->inventory->get_object(p->inventory, SIBUR),
	   p->inventory->get_object(p->inventory, DERAUMERE),
	   p->inventory->get_object(p->inventory, MENDIANE));
  snprintf(str, 512, "%s, phiras %d, thystame %d, nourriture %d}\n", str1,
	   p->inventory->get_object(p->inventory, PHIRAS),
	   p->inventory->get_object(p->inventory, THYSTAME),
	   ((int)(p->time)));
  add_str_in_buffer(&p->buffer_circular, str);
  p->mode = WRITE;
  return (0);
}
