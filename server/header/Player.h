#ifndef 	PLAYER_H_
# define 	PLAYER_H_

# include <stdlib.h>
# include "Inventory.h"
# include "CircularBuffer.h"

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
	CircularBuffer	buffer_circular;
	/* Methods */
	Inventory 		*(*get_inventory)(struct Player *);
	void			(*set_inventory)(struct Player *, Inventory *);
	int 			(*fct_read)(struct Player *, void *);
}					Player;

int 	init_player(struct Player *, int);
int 	destroy_player(struct Player *);
int 	fct_read(Player *, void *);

#endif 	/* PLAYER_H_ */