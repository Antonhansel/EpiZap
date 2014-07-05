#include "command_functions.h"

int 	take_object_cmd(Server *s, Player *p, char *cmd)
{
	int i;

	i = 0;
	p->mode = WRITE;
	while (i < ((int)(strlen(cmd))) && *cmd != ' ')
	{
		(*cmd)++;
		i++;
	}
	(*cmd)++;
	if ((i = get_obj(s, i, cmd)) != -1)
	{
		if (s->map->map[p->x][p->y].inventory->get_object(s->map->map[p->x][p->y].inventory, i) > 0)
		{
			s->map->map[p->x][p->y].inventory->set_object(s->map->map[p->x][p->y].inventory, i, -1);
			p->inventory->set_object(p->inventory, i, 1);
			add_str_in_buffer(&p->buffer_circular, "OK\n");
			return (0);
		}
	}
	add_str_in_buffer(&p->buffer_circular, "KO\n");
	return (0);
}

int 	put_object_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}

int 	kick_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}

int 	broadcast_text_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}

int 	incantation_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)p;
	(void)cmd;
	return (0);
}