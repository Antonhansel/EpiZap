#include "command_functions.h"

int			fork_egg(void *s, Player *p, char *cmd)
{
	Team 	*tmp;
	int 	ret;

	ret = 0;
	tmp = ((Server*)(s))->team;
	printf("OPENING SLOT\n");
	while (ret != 1 && tmp)
	{
		if (strcmp(tmp->name, p->team_name) == 0)
		{
			tmp->nb_player_max++;
			ret = 1;			
		}
		tmp = tmp->next;
	}
	(void)cmd;
	return (0);
}

char		*see_next(void *serv, char *str, int x, int y)
{
	int		i;
	int 	nb;
	Server	*s;

	i = -1;
	s = ((Server*)(serv));
	if (str == NULL)
	{
		if ((str = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
			return (NULL);
		str = memset(str, 0, BUFFER_SIZE);
		str = strcat(str, "{");
	}
	while (++i < 7)
	{
		nb = s->map->map[y][x].inventory->get_object(s->map->map[y][x].inventory, i);
		if (nb != 0)
		{
			str = strcat(str, " ");
			str = strcat(str, s->obj_type[i]);
		}
	}
	str = strcat(str, ",");
	return (str);
}

int 		see_loop(void *s, Player *p, int di, int dj)
{
	int 	r;
	int 	c;
	int 	x;
	int 	y;
	char	*str;

	r = 0;
	str = NULL;
	while (r < p->range)
	{
		c = r;
		while (c >= -r)
		{
			y = (p->x + r * di + c * dj + ((Server*)(s))->map->width) % ((Server*)(s))->map->width;
			x = (p->y + c * di + r * dj * -1 + ((Server*)(s))->map->height) % ((Server*)(s))->map->height;
			str = see_next(s, str, x, y);
			c--;
		}
		r++;
	}
	str = strcat(str, "\b}\n");
	add_str_in_buffer(&p->buffer_circular, str);
	p->mode = WRITE;
	return (0);
}