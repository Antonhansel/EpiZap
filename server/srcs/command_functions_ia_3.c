#include "command_functions.h"

int 	fork_cmd(Server *s, Player *p)
{
	(void)s;
	(void)p;
	return (0);
}

int 		connect_nbr_cmd(Server *s, Player *p)
{
	Team	*tmp;
	char	res[32];

	tmp = s->team;
	while (tmp)
	{
		if (strcmp(tmp->name, p->team_name) == 0)
			sprintf(res, "%d\n", tmp->nb_player_max - tmp->nb_player_actu);
		tmp = tmp->next;
	}
	add_str_in_buffer(&p->buffer_circular, res);
	p->mode = WRITE;
	return (0);
}