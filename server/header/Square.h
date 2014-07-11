#ifndef	SQUARE_H_
# define SQUARE_H_

# include <stdlib.h>
# include <time.h>
# include "Inventory.h"
# include "Player.h"

typedef struct	s_square
{
	/* Attributes */
	int 		square_type;
	t_inventory	*inventory;
	t_player		*player;
	/* Methods*/
	t_inventory 	*(*get_inventory)(struct s_square *);
	void		(*set_inventory)(struct s_square *, struct s_inventory *);
	t_player 		*(*get_player)(struct s_square *);
}				t_square;

int 	init_square(t_square *);
int 	destroy_square(t_square *);

#endif