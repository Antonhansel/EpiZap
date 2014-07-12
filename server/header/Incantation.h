#ifndef INCANTATION_H_
# define INCANTATION_H_

# include "Inventory.h"

typedef struct 	s_incantation
{
	/* data */
	t_inventory	*level[10];
	t_inventory	*(*get_lvl)(struct s_incantation *, int);
}				t_incantation;

#endif /* INCANTATION_H_ */