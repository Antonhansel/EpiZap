#include "start_functions.h"
#include "List.h"

void	assign_to_team_next(Player *, Server *, char *);

void 		assign_to_team(Player *this, Server *s)
{
	char	*team_name;

	printf("PLAYER = %d\n", this->fd);
	display_circular_buffer(this->buffer_circular, 1);
	team_name = get_data_of_buffer(this->buffer_circular);
	if (team_name != NULL)
		assign_to_team_next(this, s, team_name);
	free(team_name);
	s = s;
}

void	assign_to_team_next(Player *this, Server *s, char *team_name)
{
	Team 	*tmp;
	char	buf[64];
	int 	find;
	int 	nb_co;

	find = 0;
	tmp = s->team;
	reset_elem_in_buffer(&this->buffer_circular, strlen(team_name) + 1);
	this->buffer_circular = this->buffer_circular->head;
	while (tmp)
	{
		if (strcmp(tmp->name, team_name) == 0)
		{
			find = 1;
			this->team_name = strdup(team_name);
			set_player_data(this, s->map->width, s->map->height);
			add_player(&tmp->player_list, this);
			display_list(tmp->player_list);
			tmp->nb_player_actu++;
			nb_co = tmp->nb_player_max - tmp->nb_player_actu;
		}
		tmp = tmp->next;
	}
	if (find == 1)
	{
		printf("---- ASSIGN PLAYER %d TO TEAM %s----\n", this->fd, team_name);
		this->intro = FALSE;
		this->mode = WRITE;
		sprintf(buf, "%d\n%d %d\n", nb_co, s->map->width, s->map->height);
		add_str_in_buffer(&this->buffer_circular, buf);
	}
}