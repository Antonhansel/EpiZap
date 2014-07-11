#include "command_functions.h"

int 		fork_cmd(void *s, t_player *p, char *cmd)
{
	t_cmd 	*new_cmd;

	printf("CMD = %s\n", cmd);
	new_cmd = create_new_cmd(s, p, "fork");
	new_cmd->num_cmd = -1;
	new_cmd->func = &fork_egg;
	new_cmd->time = 620.0 / ((t_server*)(s))->ctime;
	add_cmd_in_list(&((t_server*)(s))->cmd_list, new_cmd);
	add_str_in_buffer(&p->buffer_circular, "ok\n");
	p->mode = WRITE;
	(void)cmd;
	(void)s;
	return (0);
}

int 		connect_nbr_cmd(void *s, t_player *p, char *cmd)
{
	t_team	*tmp;
	char	res[32];

	(void)cmd;
	tmp = ((t_server*)(s))->team;
	while (tmp)
	{
		if (strcmp(tmp->name, p->team_name) == 0)
			snprintf(res, 32, "%d\n", tmp->nb_player_max - tmp->nb_player_actu);
		tmp = tmp->next;
	}
	add_str_in_buffer(&p->buffer_circular, res);
	p->mode = WRITE;
	return (0);
}

int 	get_obj(void *s, int i, char *cmd)
{
	i = 0;
	printf("CMD === |%s|\n", cmd);
	while (cmd && i < 7)
	{
		if (strncmp(cmd, ((t_server*)(s))->obj_type[i], strlen(cmd)) == 0)
			return (i);
		++i;
	}	
	return (-1);
}

char		*get_dir(t_player *expulse, t_player *to_expulse)
{
	char	*str;
	int		dir;
	int		square;
	int		dir_to_expulse;

	square = 1;
	dir = to_expulse->dir;
	dir_to_expulse = expulse->dir + 2;
	(dir_to_expulse > 3) ? (dir_to_expulse = dir_to_expulse - 4) : 0;
	if ((str = malloc(sizeof(char) * 256)) == NULL)
		return (NULL);
	while (dir != dir_to_expulse)
	{
		square += 2;
		dir--;
		if (dir == -1)
			dir = 3;
	}
	memset(str, 0, 256);
	snprintf(str, 256, "deplacement: %d\n", square);
	return (str);
}

int			kick_cmd_next(void *s, t_player *p, t_player *tmp)
{
	int 	old_dir;
	char	*res;

	while (tmp)
	{
		if (tmp->fd != p->fd)
		{
			tmp->sent = FALSE;
			old_dir = tmp->dir;
			tmp->dir = p->dir;
			up_cmd(((t_server*)(s)), tmp, NULL);
			tmp->dir = old_dir;
			res = get_dir(p, tmp);
			if (res != NULL)
			{
				add_str_in_buffer(&tmp->buffer_circular, res);
				tmp->mode = WRITE;
				free(res);
			}
			tmp->sent = TRUE;
			return (1);
		}
		tmp = tmp->next_square;
	}
	return (0);
}