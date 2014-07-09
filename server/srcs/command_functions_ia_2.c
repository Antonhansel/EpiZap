#include "command_functions.h"

int		kick_cmd_next(void *, Player *, Player *);
char	**my_str_to_wordtab(char *);

int 		take_object_cmd(void *s, Player *p, char *cmd)
{
	int 	i;

	i = 0;
	p->mode = WRITE;
	if ((i = get_obj(((Server*)(s)), i, cmd)) != -1)
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

	(void)cmd;
	p->mode = WRITE;
	tmp = ((Server*)(s))->map->map[p->x][p->y].player;
	expulse = kick_cmd_next(((Server*)(s)), p, tmp);
	if (expulse == 1)
		add_str_in_buffer(&p->buffer_circular, "OK\n");
	else
		add_str_in_buffer(&p->buffer_circular, "KO\n");
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