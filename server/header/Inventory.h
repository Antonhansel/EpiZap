#ifndef 		INVENTORY_H_
# define 		INVENTORY_H_

# include 		"string.h"

enum ROCK
{
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	FOOD
};

typedef struct 	Inventory
{
	/* data */
	int 		nbPlayer; // NB PLAYER OF THE CASE
	int 		tab[10]; // TABLEAU DE CORRESPONDANCE
	/* Method */
	int			(*get_object)(struct Inventory *, int);
	void 		(*set_object)(struct Inventory *, int, int);
}				Inventory;

int				init_inventory(Inventory *);
int 			destroy_inventory(Inventory *);

#endif 			/* INVENTORY_H_ */