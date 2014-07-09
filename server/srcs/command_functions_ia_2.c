#include "command_functions.h"

int		kick_cmd_next(void *, Player *, Player *);

int 	take_object_cmd(void *s, Player *p, char *cmd)
{
	int i;

	i = 0;
	p->mode = WRITE;
	printf("-------->|%s|\n", cmd);
	while (i < ((int)(strlen(cmd))) && *cmd != ' ')
	{
		cmd++;
		i++;
	}
	cmd++;
	if ((i = get_obj(((Server*)(s)), (i + 1), cmd)) != -1)
	{
		if (((Server*)(s))->map->map[p->x][p->y].inventory->get_object(
			((Server*)(s))->map->map[p->x][p->y].inventory, i) > 0)
		{
			((Server*)(s))->map->map[p->x][p->y].inventory->set_object(
				((Server*)(s))->map->map[p->x][p->y].inventory, i, -1);
			p->inventory->set_object(p->inventory, i, 1);
			add_str_in_buffer(&p->buffer_circular, "OK\n");
			return (0);
		}
	}
	add_str_in_buffer(&p->buffer_circular, "KO\n");
	return (0);
}

int 	put_object_cmd(void *s, Player *p, char *cmd)
{
	int i;

	i = 0;
	p->mode = WRITE;
	while (i < ((int)(strlen(cmd))) && *cmd != ' ')
	{
		cmd++;
		i++;
	}
	cmd++;
	if ((i = get_obj(((Server*)(s)), i, cmd)) != -1)
	{
		if (p->inventory->get_object(p->inventory, i) > 0)
		{
			((Server*)(s))->map->map[p->x][p->y].inventory->set_object(
				((Server*)(s))->map->map[p->x][p->y].inventory, i, 1);
			p->inventory->set_object(p->inventory, i, -1);
			add_str_in_buffer(&p->buffer_circular, "OK\n");
			return (0);
		}
	}
	add_str_in_buffer(&p->buffer_circular, "KO\n");
	return (0);
}

int 		kick_cmd(void *s, Player *p, char *cmd)
{
	Player	*tmp;
	int 	expulse;

	p->mode = WRITE;
	tmp = ((Server*)(s))->map->map[p->x][p->y].player;
	expulse = kick_cmd_next(((Server*)(s)), p, tmp);
	if (expulse == 1)
		add_str_in_buffer(&p->buffer_circular, "OK\n");
	else
		add_str_in_buffer(&p->buffer_circular, "KO\n");
	(void)cmd;
	return (0);
}

int 	broadcast_text_cmd(void *s, Player *p, char *cmd)
{
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}

int 	incantation_cmd(void *s, Player *p, char *cmd)
{
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}