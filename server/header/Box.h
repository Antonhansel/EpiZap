#ifndef BOX_H_
# define BOX_H_

# include "Inventory.h"
# include "Player.h"

typedef struct 	Box
{
	/* data */
	Player 		*player;
	Inventory	*inventory;
}				Box;

#endif /* BOX_H_ */