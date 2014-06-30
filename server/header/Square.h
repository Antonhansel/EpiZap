#ifndef			SQUARE_H_
# define		SQUARE_H_

# include		<stdlib.h>
# include		<time.h>
# include		"Inventory.h"
# include		"Player.h"

typedef struct	Square
{
	/* Attributes */
	int 		square_type;
	Inventory	*inventory;
	// Player		*player;

	/* Methods*/
	Inventory 	*(*get_inventory)(struct Square *);
	void		(*set_inventory)(struct Square *, struct Inventory *);
	int 		(*get_square_type)(struct Square *);
	void		(*set_square_type)(struct Square *, int);

	// Player 		*(*get_player)(struct Square *);
}				Square;

int 			init_square(struct Square *, struct Inventory *);
int 			destroy_square(struct Square *);

#endif