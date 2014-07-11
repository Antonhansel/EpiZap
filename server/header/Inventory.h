#ifndef INVENTORY_H_
# define INVENTORY_H_

# include <pthread.h>
# include <stdlib.h>
# include "string.h"
# include "Network.h"

typedef struct 		s_inventory
{
	/* data */
	int 			nbPlayer; // NB PLAYER OF THE CASE
	int 			tab[10]; // TABLEAU DE CORRESPONDANCE
	pthread_mutex_t	*mutex;
	/* Method */
	int				(*get_object)(struct s_inventory *, int);
	void 			(*set_object)(struct s_inventory *, int, int);
}					t_inventory;

int 	init_inventory(t_inventory *, pthread_mutex_t *, int);
int 	destroy_inventory(t_inventory *);
void	generate_inventory(t_inventory *);

#endif 			/* INVENTORY_H_ */