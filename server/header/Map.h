#ifndef 		MAP_H_
# define 		MAP_H_

# include		"Square.h"

typedef struct  Map
{
	/* Attributes */
	int			width;
	int			height;
	Square		**map;
}				Map;

int				init_map(struct Map *, int, int);
int 			destroy_map(struct Map *);

#endif