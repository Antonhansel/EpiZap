#include "start_functions.h"
#include "List.h"

void	assign_to_team_next(Player *, Server *, char *);
void	assign_to_team_next_next(Player *, Server *, char *, Team *);
void	assign_to_team_end(Player *, Server *, int);

void 		assign_to_team(Player *this, Server *s)
{
	char	*team_name;

	team_name = get_data_of_buffer(this->buffer_circular);
	if (team_name != NULL)
		assign_to_team_next(this, s, team_name);
	free(team_name);
	s = s;
}

void	assign_to_team_next(Player *this, Server *s, char *team_name)
{
	Team 	*tmp;
	int 	find;
	int 	nb_co;

	find = 0;
	tmp = s->team;
	reset_elem_in_buffer(&this->buffer_circular, strlen(team_name) + 1);
	this->buffer_circular = this->buffer_circular->head;
	while (tmp)
	{
		if (strcmp(tmp->name, team_name) == 0
			&& tmp->nb_player_actu < tmp->nb_player_max)
		{
			find = 1;
			nb_co = tmp->nb_player_max - tmp->nb_player_actu;
			assign_to_team_next_next(this, s, team_name, tmp);
		}
		tmp = tmp->next;
	}
	if (find == 1)
		assign_to_team_end(this, s, nb_co);
}

void	assign_to_team_next_next(Player *this, Server *s, char *name, Team *tmp)
{
	this->team_name = strdup(name);
	set_player_data(this, s->map->width, s->map->height);
	this->time = 1260.0 * (1.0 / s->ctime);
	add_player(&tmp->player_list, this);
	add_square(&s->map->map[this->x][this->y].player, this);
	tmp->nb_player_actu++;
}

void	assign_to_team_end(Player *this, Server *s, int nb_co)
{
	char	buf[64];

	this->intro = FALSE;
	this->mode = WRITE;
	snprintf(buf, 64, "%d\n%d %d\n", nb_co, s->map->width, s->map->height);
	add_str_in_buffer(&this->buffer_circular, buf);
}