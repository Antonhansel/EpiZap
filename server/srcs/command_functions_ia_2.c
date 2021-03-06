/*
** command_functions_ia_2.c for command_functions_ia_2.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:07:06 2014 Flavien David
** Last update sam. juil.  12 18:07:06 2014 Flavien David
*/

#include "command_functions.h"

int	kick_cmd_next(void *, t_player *, t_player *);
char	**my_str_to_wordtab(char *);

int		take_object_cmd(void *serv, t_player *p, char *cmd)
{
  t_server	*s;
  int		i;

  i = 0;
  p->mode = WRITE;
  s = ((t_server*)(serv));
  if ((i = get_obj(s, i, cmd)) != -1)
    {
      if (s->map->map[p->y][p->x].inventory->
        get_object(s->map->map[p->y][p->x].inventory, i) > 0)
	{
	  s->map->map[p->y][p->x].inventory->
    set_object(s->map->map[p->y][p->x].inventory, i, -1);
	  check_object(serv, p, i);
	  add_str_in_buffer(&p->buffer_circular, "ok\n");
	  return (0);
	}
    }
  add_str_in_buffer(&p->buffer_circular, "ko\n");
  return (0);
}

int	put_object_cmd(void *s, t_player *p, char *cmd)
{
  int	i;

  i = 0;
  p->mode = WRITE;
  while (i < ((int)(strlen(cmd))) && *cmd != ' ')
    {
      cmd++;
      i++;
    }
  cmd++;
  if ((i = get_obj(((t_server*)(s)), i, cmd)) != -1)
    {
      if (p->inventory->get_object(p->inventory, i) > 0)
	{
	  ((t_server*)(s))->map->map[p->y][p->x].inventory->
	    set_object(((t_server*)(s))->map->map[p->y][p->x].inventory, i, 1);
	  p->inventory->set_object(p->inventory, i, -1);
	  add_str_in_buffer(&p->buffer_circular, "ok\n");
	  return (0);
	}
    }
  add_str_in_buffer(&p->buffer_circular, "ko\n");
  return (0);
}

int		kick_cmd(void *s, t_player *p, char *cmd)
{
  t_player	*tmp;
  int		expulse;

  (void)cmd;
  p->mode = WRITE;
  tmp = ((t_server*)(s))->map->map[p->y][p->x].player;
  expulse = kick_cmd_next(((t_server*)(s)), p, tmp);
  if (expulse != 0)
    add_str_in_buffer(&p->buffer_circular, "ok\n");
  else
    add_str_in_buffer(&p->buffer_circular, "ko\n");
  return (0);
}

int	broadcast_text_cmd(void *s, t_player *p, char *cmd)
{
  char  str[BUFFER_SIZE];
  t_player  *tmp;
  int   res;
  int   angle;

  tmp = ((t_server*)(s))->player;
  while (tmp)
  {
    if (tmp->fd != p->fd)
    {
      res = search(p, tmp, s);
      ((t_server*)(s))->mi = (res - 1) / 3 - 1;
      ((t_server*)(s))->mj = (res - 1) % 3 - 1;
      angle = calc_angle(p, tmp, s);
      memset(str, 0, BUFFER_SIZE);
      snprintf(str, BUFFER_SIZE - 1, "message %d, %s\n", angle, cmd);
      add_str_in_buffer(&tmp->buffer_circular, str);
      tmp->mode = WRITE;
    }
    else
        add_str_in_buffer(&p->buffer_circular, "ok\n");
    tmp = tmp->next;
  }
  p->mode = WRITE;
  return (0);
}

int		incantation_cmd(void *s, t_player *p, char *cmd)
{
  t_player	*tmp;
  int		i;

  (void)cmd;
  p->mode = WRITE;
  tmp = ((t_server*)(s))->map->map[p->y][p->x].player;
  i = 0;
  while (tmp)
    {
      if (tmp->lvl == p->lvl)
	++i;
      tmp = tmp->next;
    }
  if (p->lvl < LVL8 && i >= ((t_server*)(s))->inc_tab[p->lvl + 1][6])
    if (get_rock(s, p) == TRUE)
      return (0);
  add_str_in_buffer(&p->buffer_circular, "ko\n");
  return (0);
}
