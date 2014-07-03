#include "start_functions.h"
#include "List.h"

void 		assign_to_team(Player *this, Server *s)
{
	Team 	*tmp;
	char	*team_name;
	char	buf[64];
	int 	find;

	find = 0;
	tmp = s->team;
	printf("PLAYER = %d\n", this->fd);
	display_circular_buffer(this->buffer_circular, 1);
	team_name = get_data_of_buffer(this->buffer_circular);
	reset_elem_in_buffer(&this->buffer_circular, strlen(team_name) + 1);
	this->buffer_circular = this->buffer_circular->head;
	if (team_name != NULL)
	{
		while (tmp)
		{
			if (strcmp(tmp->name, team_name) == 0)
			{
				find = 1;
				this->team_name = strdup(team_name);
				add_player(&tmp->player_list, this);
			}
			tmp = tmp->next;
		}
		if (find == 1)
		{
			printf("---- ASSIGN PLAYER %d TO TEAM %s----\n", this->fd, team_name);
			this->intro = FALSE;
			this->mode = WRITE;
			sprintf(buf, "%d %d\n", this->x, this->y);
			add_str_in_buffer(&this->buffer_circular, buf);
			printf("BUFFFFF = %s\n", buf);
		}
	}
	free(team_name);
	s = s;
}