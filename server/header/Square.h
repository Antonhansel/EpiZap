#ifndef			SQUARE_H_
# define		SQUARE_H_

# include		<stdlib.h>
# include		"Inventory.h"

typedef struct	Square
{
	/* Attributes */
	Inventory	*inventory;

	/* Methods*/
	Inventory 	*(*get_inventory)(struct Square *);
	void		(*set_inventory)(struct Square *, struct Inventory *);
}				Square;

int 			init_square(struct Square *, struct Inventory *);
int 			destroy_square(struct Square *);

#endif