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

	/*
	int 		nbPlayer; // NB PLAYER OF THE CASE
	int 		*tab[10]; // TABLEAU DE CORRESPONDANCE
	char		tab_corresp[10][20];
	*/

	/* Method */
	/*
	int			(*get_object)(struct Inventory *, char *);
	void 		(*set_object)(struct Inventory *, char *, int);
	*/
	int 		(*get_linemate)(struct Inventory *);
	void 		(*set_linemate)(struct Inventory *, int);
	int 		(*get_deraumere)(struct Inventory *);
	void 		(*set_deraumere)(struct Inventory *, int);
	int 		(*get_sibur)(struct Inventory *);
	void 		(*set_sibur)(struct Inventory *, int);
	int 		(*get_mendiane)(struct Inventory *);
	void 		(*set_mendiane)(struct Inventory *, int);
	int 		(*get_phiras)(struct Inventory *);
	void 		(*set_phiras)(struct Inventory *, int);
	int   		(*get_thystame)(struct Inventory *);
	void 		(*set_thystame)(struct Inventory *, int);
	int 		(*get_food)(struct Inventory *);
	void 		(*set_food)(struct Inventory *, int);
}				Inventory;

int				init_inventory(Inventory *);
int 			destroy_inventory(Inventory *);

//void	init_inventory_next(Inventory *);

#endif /* INVENTORY_H_ */