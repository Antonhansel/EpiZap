#ifndef			SQUARE_H_
# define		SQUARE_H_

# include		<stdlib.h>
# include		"Inventory.h"
# include		"Player.h"

typedef struct	Square
{
	/* Attributes */
	Inventory	*inventory;
	Player		*player;

	/* Methods*/
	Inventory 	*(*get_inventory)(struct Square *);
	void		(*set_inventory)(struct Square *, struct Inventory *);
	Player 		*(*get_player)(struct Square *);
}				Square;

int 			init_square(struct Square *, struct Inventory *);
int 			destroy_square(struct Square *);

#endif