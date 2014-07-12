/*
** start_functions.c for start_functions.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:08:35 2014 Flavien David
** Last update sam. juil.  12 18:08:35 2014 Flavien David
*/

#include "start_functions.h"
#include "List.h"

void	assign_to_team_next(t_player *, t_server *, char *);
void	assign_to_team_next_next(t_player *, t_server *, char *, t_team *);
void	assign_to_team_end(t_player *, t_server *, int);

void	assign_to_team(t_player *this, t_server *s)
{
  char	*team_name;

  team_name = get_data_of_buffer(this->buffer_circular);
  if (team_name != NULL)
    assign_to_team_next(this, s, team_name);
  free(team_name);
  s = s;
}

void		assign_to_team_next(t_player *this, t_server *s, char *team)
{
  t_team	*tmp;
  int		find;
  int		nb_co;

  find = 0;
  tmp = s->team;
  reset_elem_in_buffer(&this->buffer_circular, strlen(team) + 1);
  this->buffer_circular = this->buffer_circular->head;
  while (tmp)
    {
      if (strcmp(tmp->name, team) == 0
	  && tmp->nb_player_actu < tmp->nb_player_max)
	{
	  find = 1;
	  assign_to_team_next_next(this, s, team, tmp);
	  nb_co = tmp->nb_player_max - tmp->nb_player_actu;
	}
      tmp = tmp->next;
    }
  if (find == 1)
    assign_to_team_end(this, s, nb_co);
}

void	assign_to_team_next_next(t_player *p, t_server *s, char *n, t_team *t)
{
  p->team_name = strdup(n);
  set_player_data(p, s->map->width, s->map->height);
  p->time = 1260.0 * (1.0 / s->ctime);
  add_player(&t->player_list, p);
  printf("X = %d && Y = %d && DIR = %d\n", p->x, p->y, p->dir);
  add_square(&s->map->map[p->y][p->x].player, p);
  t->nb_player_actu++;
}

void	assign_to_team_end(t_player *this, t_server *s, int nb_co)
{
  char	buf[64];

  this->intro = FALSE;
  this->mode = WRITE;
  snprintf(buf, 64, "%d\n%d %d\n", nb_co, s->map->width, s->map->height);
  add_str_in_buffer(&this->buffer_circular, buf);
}
