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
	//int 	ret;
	Server	*s;

	i = -1;
	s = ((Server*)(serv));
	//ret = 0;
	if (str == NULL)
	{
		if ((str = malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
			return (NULL);
		str = memset(str, 0, BUFFER_SIZE);
	}
	while (++i < 7)
	{
		nb = s->map->map[y][x].inventory->get_object(s->map->map[y][x].inventory, i);
		if (nb != 0)
		{
			//ret = snprintf(ret + str, strlen(s->obj_type[i]), "%s ", s->obj_type[i]);
			printf("---------<< %s\n", s->obj_type[i]);
			/*else
				ret = snprintf(str, strlen(s->obj_type[i]), "%s", s->obj_type[i]);*/
		}
	}
	snprintf(str, strlen(str), "%s,", str);
	return (str);
}