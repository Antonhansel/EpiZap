#ifndef 		MAP_H_
# define 		MAP_H_

# include		"Square.h"

typedef struct  Map
{
	/* Attributes */
	int			width;
	int			height;
	Square		**map;

	/* Methods */
	int 		(*get_width)(struct Map *);
	void		(*set_width)(struct Map *, int);
	int 		(*get_height)(struct Map *);
	void		(*set_height)(struct Map *, int);
	Square 		*(*get_elem)(struct Map *, int, int);
	void		(*set_elem)(struct Map *, struct Square *, int, int);
}				Map;

int				init_map(struct Map *, int, int);
int 			destroy_map(struct Map *);

#endif