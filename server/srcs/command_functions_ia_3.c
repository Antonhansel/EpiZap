#include "command_functions.h"

int 	fork_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}

int 		connect_nbr_cmd(Server *s, Player *p, char *cmd)
{
	Team	*tmp;
	char	res[32];

	(void)cmd;
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

int 	get_obj(Server *s, int i, char *cmd)
{
	/*if (i < ((int)(strlen(cmd))))
	{*/
		i = 0;
		printf("CMD === |%s|\n", cmd);
		while (i < 7)
		{
			if (strncmp(cmd, s->obj[i], strlen(cmd)) == 0)
				return (i);
			++i;
		}	
	//}
	return (-1);
}