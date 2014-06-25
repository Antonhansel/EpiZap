#ifndef INCANTATION_H_
# define INCANTATION_H_

# include "Inventory.h"

typedef struct 	Incantation
{
	/* data */
	Inventory	*level[10];
	Inventory	*(*get_lvl)(struct Incantation *, int);
}				Incantation;

#endif /* INCANTATION_H_ */