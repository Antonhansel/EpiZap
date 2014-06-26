#ifndef INVENTORY_H_
# define INVENTORY_H_

# include "string.h"

typedef struct 	Inventory
{
	/* data */
	int 		linemate;
	int 		deraumere;
	int 		sibur;
	int 		mendiane;
	int 		phiras;
	int 		thystame;
	int 		food;
	int 		nbPlayer; // NB PLAYER OF THE CASE
	int 		*tab[10]; // TABLEAU DE CORRESPONDANCE
	char		tab_corresp[10][20];
	int			(*get_object)(struct Inventory *, char *);
}				Inventory;

void	init_inventory(Inventory *);
void	init_inventory_next(Inventory *);

#endif /* INVENTORY_H_ */