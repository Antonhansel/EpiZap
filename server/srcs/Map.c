#include <stdlib.h>
#include "Map.h"
#include "Square.h"
#include "xfunction.h"

static int 		alloc_map_attr(Map *);
static void		free_map_attr(Map *);

int		init_map(Map *this, int w, int h)
{
	this->width = w;
	this->height = h;
	srand(time(NULL));
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
	if (!(this->map = xmalloc(sizeof(Square *) * (this->height + 1)))) 
		return (-1);
	i = 0;
	while (i < this->height)
		{
			if (!(this->map[i] = xmalloc(sizeof(Square) * (this->width + 1))))
				return (-1);
			++i;
		}
	i = 0;
	while (i < this->width)
	{
		x = 0;
		while (x < this->height)
		{
			this->map[i][x].square_type = rand() % 7;
			x++;
		}
		i++;
	}
	return (0);
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