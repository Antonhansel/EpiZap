#include "start_functions.h"

void 		assign_to_team(Player *this, Server *s)
{
	char	*team_name;
	char	buf[64];

	display_circular_buffer(this->buffer_circular, 0);
	team_name = get_data_of_buffer(this->buffer_circular);
	reset_elem_in_buffer(&this->buffer_circular, strlen(team_name) + 1);
	this->buffer_circular = this->buffer_circular->head;
	if (team_name != NULL)
	{
		printf("---- ASSIGN PLAYER %d TO TEAM %s----\n", this->fd, team_name);
		// VERIFIER LA TEAM
	}
	free(team_name);
	this->intro = FALSE;
	s = s;
	this->mode = WRITE;
	sprintf(buf, "%d %d\n", this->x, this->y);
	add_str_in_buffer(&this->buffer_circular, buf);
	printf("BUFFFFF = %s\n", buf);
}