#include "cmd.h"
#include "Server.h"
#include "CircularBuffer.h"

int 		set_cmd_information(Server *, Player *, t_cmd *, char *);

int 		get_cmd_type(Server *s, char *cmd)
{
	int 	i;

	i = -1;
	while (++i < 12)
	{
		if (strncmp(s->cmd_type[i], cmd, strlen(s->cmd_type[i])) == 0)
			return (i);
	}
	return (-1);
}

int			set_cmd_information(Server *s, Player *p, t_cmd *new_cmd, char *cmd)
{
	int 	good;

	good = TRUE;
	new_cmd->cmd = strdup(cmd);
	new_cmd->func = NULL;
	new_cmd->time = 0;
	if ((new_cmd->type = get_cmd_type(s, new_cmd->cmd)) == -1)
		good = FALSE;
	if (good == TRUE)
	{
		new_cmd->time = s->time_tab[new_cmd->type];
		new_cmd->func = s->cmd_tab[new_cmd->type];
	}
	new_cmd->owner = p;
	new_cmd->num_cmd = p->nb_request;
	new_cmd->next = NULL;
	return (TRUE);
}

t_cmd		*create_new_cmd(void *s, Player *p, char *cmd)
{
	t_cmd 	*new_cmd;
	Server	*server;

	server = (Server *)s;
	if (!(new_cmd = malloc(sizeof(t_cmd))))
		return (NULL);
	if (set_cmd_information(server, p, new_cmd, cmd) == FALSE)
	{
		free(new_cmd->cmd);
		free(new_cmd);
		return (NULL);
	}
	return (new_cmd);
}

int			add_cmd_in_list(t_cmd **list, t_cmd *new_cmd)
{
	t_cmd 	*tmp;
	t_cmd	*save;

	tmp = (*list);
	save = NULL;
	while (tmp)
	{
		if (tmp->num_cmd == new_cmd->num_cmd)
		{
			new_cmd->next = tmp->next;
			tmp->next = new_cmd;
			return (TRUE);
		}
		save = tmp;
		tmp = tmp->next;
	}
	if (!save)
		(*list) = new_cmd;
	else
		save->next = new_cmd;
	return (TRUE);
}

int 		del_cmd_in_list(t_cmd *list, t_cmd *cmd)
{
	t_cmd	*tmp;
	t_cmd	*save;

	if (list == cmd)
	{
		list = tmp->next;
		return (TRUE);
	}
	else
	{
		tmp = list;
		while (tmp)
		{
			if (tmp->next == cmd)
			{
				save = tmp->next;
				tmp->next = tmp->next->next;
				free(save);
				return (TRUE);		
			}
			tmp = tmp->next;
		}
	}
	return (FALSE);
}

void 	display_list_queue(t_cmd *list)
{
	t_cmd 	*tmp;

	tmp = list;
	while (tmp)
	{
		printf("---> %d : %s WITH %d\n", tmp->owner->fd, tmp->cmd, tmp->num_cmd);
		tmp = tmp->next;
	}
}