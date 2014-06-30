#ifndef 	PLAYER_H_
# define 	PLAYER_H_

# include	<stdlib.h>
# include 	"Inventory.h"

typedef struct 		Player
{
	/* Attributes */
	int				fd;
	int				lvl;
	float			time;
	int 		 	x;
	int 			y;
	Inventory		*inventory;
	int				nb_request;
	struct Player 	*next;
	/* Methods */
	Inventory 		*(*get_inventory)(struct Player *);
	void			(*set_inventory)(struct Player *, Inventory *);
}					Player;

int 	init_player(struct Player *, int);
int 	destroy_player(struct Player *);

#endif 	/* PLAYER_H_ */