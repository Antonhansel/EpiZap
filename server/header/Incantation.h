#ifndef INCANTATION_H_
# define INCANTATION_H_

# include "Inventory.h"

typedef struct 	Incantation
{
	/* data */
	t_inventory	*level[10];
	t_inventory	*(*get_lvl)(struct Incantation *, int);
}				Incantation;

#endif /* INCANTATION_H_ */