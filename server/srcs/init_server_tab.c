#include "Server.h"
#include "command_functions.h"

void	init_cmd_tab(Server *s)
{
	strcpy(s->cmd_type[AVANCE], "avance");
	strcpy(s->cmd_type[DROITE], "droite");
	strcpy(s->cmd_type[GAUCHE], "gauche");
	strcpy(s->cmd_type[VOIR], "voir");
	strcpy(s->cmd_type[INVENTAIRE], "inventaire");
	strcpy(s->cmd_type[PREND_OBJET], "prend");
	strcpy(s->cmd_type[POSE_OBJET], "pose");
	strcpy(s->cmd_type[EXPULSE], "expulse");
	strcpy(s->cmd_type[BROADCAST_TEXTE], "broadcast");
	strcpy(s->cmd_type[INCANTATION], "incantation");
	strcpy(s->cmd_type[FORK], "fork");
	strcpy(s->cmd_type[CONNECT_NBR], "connect_nbr");
}

void	init_time_tab(Server *s)
{
	s->time_tab[AVANCE] = 7;
	s->time_tab[DROITE] = 7;
	s->time_tab[GAUCHE] = 7;
	s->time_tab[VOIR] = 7;
	s->time_tab[INVENTAIRE] = 1;
	s->time_tab[PREND_OBJET] = 7;
	s->time_tab[POSE_OBJET] = 7;
	s->time_tab[EXPULSE] = 7;
	s->time_tab[BROADCAST_TEXTE] = 7;
	s->time_tab[INCANTATION] = 300;
	s->time_tab[FORK] = 42;
	s->time_tab[CONNECT_NBR] = 0;
}

void	init_obj_tab(Server *s)
{
	strcpy(s->obj_type[LINEMATE], "linemate");
	strcpy(s->obj_type[DERAUMERE], "deraumere");
	strcpy(s->obj_type[SIBUR], "sibur");
	strcpy(s->obj_type[MENDIANE], "mendiane");
	strcpy(s->obj_type[PHIRAS], "phiras");
	strcpy(s->obj_type[THYSTAME], "thystame");
	strcpy(s->obj_type[FOOD], "food");	
}

void	init_tab_ptr(Server *s)
{
	s->exe_cmd[AVANCE] = &up_cmd;
	s->exe_cmd[DROITE] = &right_cmd;
	s->exe_cmd[GAUCHE] = &left_cmd;
	s->exe_cmd[VOIR] = &see_cmd;
	s->exe_cmd[INVENTAIRE] = &inventory_cmd;
	s->exe_cmd[PREND_OBJET] = &take_object_cmd;
	s->exe_cmd[POSE_OBJET] = &put_object_cmd;
	s->exe_cmd[EXPULSE] = &kick_cmd;
	s->exe_cmd[BROADCAST_TEXTE] = &broadcast_text_cmd;
	s->exe_cmd[INCANTATION] = &incantation_cmd;
	s->exe_cmd[FORK] = &fork_cmd;
	s->exe_cmd[CONNECT_NBR] = &connect_nbr_cmd;
}