#ifndef		SQUARE_H_
# define	SQUARE_H_

# include	<stdlib.h>
# include	<time.h>
# include	"Inventory.h"
# include	"Player.h"

typedef struct	Square
{
	/* Attributes */
	int 		square_type;
	Inventory	*inventory;
	Player		*player;
	/* Methods*/
	Inventory 	*(*get_inventory)(struct Square *);
	void		(*set_inventory)(struct Square *, struct Inventory *);
	Player 		*(*get_player)(struct Square *);
}				Square;

int 	init_square(struct Square *);
int 	destroy_square(struct Square *);

#endif