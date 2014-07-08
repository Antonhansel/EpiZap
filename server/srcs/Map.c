#include <stdlib.h>
#include "Map.h"
#include "Square.h"

static int 		alloc_map_attr(Map *);
static void		free_map_attr(Map *);

int		init_map(Map *this, int w, int h)
{
	this->width = w;
	this->height = h;
	if (alloc_map_attr(this) == -1)
		return (-1);
	return (0);
}

int 	destroy_map(Map *this)
{
	free_map_attr(this);
	return (0);
}

static int 		alloc_map_attr(Map *this)
{
	int 		i;
	int 		x;
	if (!(this->map = malloc(sizeof(Square *) * (this->height)))) 
		return (FALSE);
	i = 0;
	while (i < this->height)
		{
			if (!(this->map[i] = malloc(sizeof(Square) * (this->width))))
				return (FALSE);
			++i;
		}
	i = 0;
	while (i < this->height)
	{
		x = 0;
		while (x < this->width)
		{
			this->map[i][x].square_type = rand() % 7;
			if (init_square(&this->map[i][x]) == FALSE)
				return (FALSE);
			x++;
		}
		i++;
	}
	return (TRUE);
}

static void		free_map_attr(Map *this)
{
	int 		i;

	i = 0;
	while (i < this->height + 1)
		{
			free(this->map[i]);
			++i;
		}
	free(this->map);
}