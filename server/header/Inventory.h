#ifndef INVENTORY_H_
# define INVENTORY_H_

# include <pthread.h>
# include <stdlib.h>
# include "string.h"
# include "Network.h"

typedef struct 		Inventory
{
	/* data */
	int 			nbPlayer; // NB PLAYER OF THE CASE
	int 			tab[10]; // TABLEAU DE CORRESPONDANCE
	pthread_mutex_t	*mutex;
	/* Method */
	int				(*get_object)(struct Inventory *, int);
	void 			(*set_object)(struct Inventory *, int, int);
}					Inventory;

int 	init_inventory(Inventory *, pthread_mutex_t *, int);
int 	destroy_inventory(Inventory *);
void	generate_inventory(Inventory *);

#endif 			/* INVENTORY_H_ */