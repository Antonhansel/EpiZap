#ifndef MAP_H_
# define MAP_H_

# include "Square.h"

typedef struct  s_map
{
	/* Attributes */
	int			width;
	int			height;
	t_square		**map;
}				t_map;

int				init_map(t_map *, int, int);
int 			destroy_map(t_map *);

#endif