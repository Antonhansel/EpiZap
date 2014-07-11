#include "Server.h"
#include "command_functions.h"

void	init_cmd_tab(t_server *s)
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

void	init_time_tab(t_server *s)
{
	s->time_tab[AVANCE] = 7.0 / s->ctime;
	s->time_tab[DROITE] = 7.0 / s->ctime;
	s->time_tab[GAUCHE] = 7.0 / s->ctime;
	s->time_tab[VOIR] = 7.0 / s->ctime;
	s->time_tab[INVENTAIRE] = 1.0 / s->ctime;
	s->time_tab[PREND_OBJET] = 7.0 / s->ctime;
	s->time_tab[POSE_OBJET] = 7.0 / s->ctime;
	s->time_tab[EXPULSE] = 7.0 / s->ctime;
	s->time_tab[BROADCAST_TEXTE] = 7.0 / s->ctime;
	s->time_tab[INCANTATION] = 300.0 / s->ctime;
	s->time_tab[FORK] = 42.0 / s->ctime;
	s->time_tab[CONNECT_NBR] = 0.0;
}

void	init_obj_tab(t_server *s)
{
	strcpy(s->obj_type[LINEMATE], "linemate");
	strcpy(s->obj_type[DERAUMERE], "deraumere");
	strcpy(s->obj_type[SIBUR], "sibur");
	strcpy(s->obj_type[MENDIANE], "mendiane");
	strcpy(s->obj_type[PHIRAS], "phiras");
	strcpy(s->obj_type[THYSTAME], "thystame");
	strcpy(s->obj_type[FOOD], "food");	
}

void	init_tab_ptr(t_server *s)
{
	s->cmd_tab[AVANCE] = &up_cmd;
	s->cmd_tab[DROITE] = &right_cmd;
	s->cmd_tab[GAUCHE] = &left_cmd;
	s->cmd_tab[VOIR] = &see_cmd;
	s->cmd_tab[INVENTAIRE] = &inventory_cmd;
	s->cmd_tab[PREND_OBJET] = &take_object_cmd;
	s->cmd_tab[POSE_OBJET] = &put_object_cmd;
	s->cmd_tab[EXPULSE] = &kick_cmd;
	s->cmd_tab[BROADCAST_TEXTE] = &broadcast_text_cmd;
	s->cmd_tab[INCANTATION] = &incantation_cmd;
	s->cmd_tab[FORK] = &fork_cmd;
	s->cmd_tab[CONNECT_NBR] = &connect_nbr_cmd;
}

void	init_inc_tab(t_server *s)
{
	init_inc_tab_1(s);
	init_inc_tab_2(s);
	init_inc_tab_3(s);
}