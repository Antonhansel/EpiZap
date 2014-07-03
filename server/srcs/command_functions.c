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
	strcpy(tab[5], "prend objet");
	strcpy(tab[6], "pose objet");
	strcpy(tab[7], "expulse");
	strcpy(tab[8], "broadcast texte");
	strcpy(tab[9], "incantation");
	strcpy(tab[10], "fork");
	strcpy(tab[11], "connect_nbr");
	i = 0;
	while (i < 12)
	{
		if (strcmp(tab[i], cmd) == 0)
			return (i);
		++i;
	}
	return (-1);
}

int			command_functions(Server *s, Player *p, char *cmd)
{
	int 	(*tab[12])(Server *, Player *);
	int 	i;

	tab[AVANCE] = &up_cmd;
	tab[DROITE] = &right_cmd;
	tab[GAUCHE] = &left_cmd;
	tab[VOIR] = &see_cmd;
	tab[INVENTAIRE] = &inventory_cmd;
	tab[PREND_OBJET] = &take_object_cmd;
	tab[POSE_OBJET] = &put_object_cmd;
	tab[EXPULSE] = &kick_cmd;
	tab[BROADCAST_TEXTE] = &broadcast_text_cmd;
	tab[INCANTATION] = &incantation_cmd;
	tab[FORK] = &fork_cmd;
	tab[CONNECT_NBR] = &connect_nbr_cmd;
	if ((i = get_cmd_type(cmd)) != -1)
		tab[i](s, p);
	return (0);
}