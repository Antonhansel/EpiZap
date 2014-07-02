#include "start_functions.h"

void 		assign_to_team(Player *this, Server *s)
{
	char	*team_name;

	team_name = get_data_of_buffer(this->buffer_circular);
	reset_elem_in_buffer(&this->buffer_circular, strlen(team_name) + 1);
	if (team_name != NULL)
	{
		printf("---- ASSIGN PLAYER %d TO TEAM %s----\n", this->fd, team_name);
		// VERIFIER LA TEAM
	}
	this->intro = FALSE;
	s = s;
}