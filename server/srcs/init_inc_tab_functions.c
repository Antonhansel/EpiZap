#include "Server.h"

void	init_inc_tab_1(t_server *s)
{
	s->inc_tab[LVL1][LINEMATE] = 0;
	s->inc_tab[LVL1][DERAUMERE] = 0;
	s->inc_tab[LVL1][SIBUR] = 0;
	s->inc_tab[LVL1][MENDIANE] = 0;
	s->inc_tab[LVL1][PHIRAS] = 0;
	s->inc_tab[LVL1][THYSTAME] = 0;
	s->inc_tab[LVL1][6] = 0;
	s->inc_tab[LVL2][LINEMATE] = 1;
	s->inc_tab[LVL2][DERAUMERE] = 0;
	s->inc_tab[LVL2][SIBUR] = 0;
	s->inc_tab[LVL2][MENDIANE] = 0;
	s->inc_tab[LVL2][PHIRAS] = 0;
	s->inc_tab[LVL2][THYSTAME] = 0;
	s->inc_tab[LVL2][6] = 1;
	s->inc_tab[LVL3][LINEMATE] = 1;
	s->inc_tab[LVL3][DERAUMERE] = 1;
	s->inc_tab[LVL3][SIBUR] = 1;
	s->inc_tab[LVL3][MENDIANE] = 0;
	s->inc_tab[LVL3][PHIRAS] = 0;
	s->inc_tab[LVL3][THYSTAME] = 0;
	s->inc_tab[LVL3][6] = 2;
}

void	init_inc_tab_2(t_server *s)
{
	s->inc_tab[LVL4][LINEMATE] = 2;
	s->inc_tab[LVL4][DERAUMERE] = 0;
	s->inc_tab[LVL4][SIBUR] = 1;
	s->inc_tab[LVL4][MENDIANE] = 0;
	s->inc_tab[LVL4][PHIRAS] = 2;
	s->inc_tab[LVL4][THYSTAME] = 0;
	s->inc_tab[LVL4][6] = 2;
	s->inc_tab[LVL5][LINEMATE] = 1;
	s->inc_tab[LVL5][DERAUMERE] = 1;
	s->inc_tab[LVL5][SIBUR] = 2;
	s->inc_tab[LVL5][MENDIANE] = 0;
	s->inc_tab[LVL5][PHIRAS] = 1;
	s->inc_tab[LVL5][THYSTAME] = 0;
	s->inc_tab[LVL5][6] = 4;
	s->inc_tab[LVL6][LINEMATE] = 1;
	s->inc_tab[LVL6][DERAUMERE] = 2;
	s->inc_tab[LVL6][SIBUR] = 1;
	s->inc_tab[LVL6][MENDIANE] = 3;
	s->inc_tab[LVL6][PHIRAS] = 0;
	s->inc_tab[LVL6][THYSTAME] = 0;
	s->inc_tab[LVL6][6] = 4;
}

void 	init_inc_tab_3(t_server *s)
{
	s->inc_tab[LVL7][LINEMATE] = 1;
	s->inc_tab[LVL7][DERAUMERE] = 2;
	s->inc_tab[LVL7][SIBUR] = 3;
	s->inc_tab[LVL7][MENDIANE] = 0;
	s->inc_tab[LVL7][PHIRAS] = 1;
	s->inc_tab[LVL7][THYSTAME] = 0;
	s->inc_tab[LVL7][6] = 6;
	s->inc_tab[LVL8][LINEMATE] = 2;
	s->inc_tab[LVL8][DERAUMERE] = 2;
	s->inc_tab[LVL8][SIBUR] = 2;
	s->inc_tab[LVL8][MENDIANE] = 2;
	s->inc_tab[LVL8][PHIRAS] = 2;
	s->inc_tab[LVL8][THYSTAME] = 1;
	s->inc_tab[LVL8][6] = 6;	
}