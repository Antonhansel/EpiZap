#include <string.h>
#include "command_functions.h"

int 		get_cmd_type(char *cmd)
{
	char 	tab[12][15];
	int 	i;

	strcpy(tab[0], "avance");
	strcpy(tab[1], "droite");
	strcpy(tab[2], "gauche");
	strcpy(tab[3], "voir");
	strcpy(tab[4], "inventaire");
	strcpy(tab[5], "prend");
	strcpy(tab[6], "pose");
	strcpy(tab[7], "expulse");
	strcpy(tab[8], "broadcast");
	strcpy(tab[9], "incantation");
	strcpy(tab[10], "fork");
	strcpy(tab[11], "connect_nbr");
	i = 0;
	while (i < 12)
	{
		if (strncmp(tab[i], cmd, strlen(tab[i])) == 0)
			return (i);
		++i;
	}
	return (-1);
}

int			command_functions(Server *s, Player *p, char *cmd)
{
	int 	i;

	if ((i = get_cmd_type(cmd)) != -1)
	{
		s->exe_cmd[i](s, p, cmd);
		return (TRUE);		
	}
	return (FALSE);
}