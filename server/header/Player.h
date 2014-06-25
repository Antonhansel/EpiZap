#ifndef PLAYER_H_
# define PLAYER_H_

# include <stdlib.h>
# include "Inventory.h"

typedef struct 		Player
{
	int				fd;
	int				nbRequest;
	int				x;
	int				y;
	int				lvl;
	float			time;
	Inventory		*inventory;
	struct Player 	*next;
}					Player;

int 	init_player(Player *, int);

#endif /* PLAYER_H_ */