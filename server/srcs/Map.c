#include <stdlib.h>
#include "Map.h"
#include "Square.h"
#include "xfunction.h"

static void		init_func_ptr(Map *);

static int 		alloc_map_attr(Map *);
static void		free_map_attr(Map *);

static int 		get_width(Map *);
static void		set_width(Map *, int);
static int 		get_height(Map *);
static void		set_height(Map *, int);
static Square	*get_elem(Map *, int, int);
static void		set_elem(Map *, Square *, int, int);

int				init_map(Map *this, int w, int h)
{
	this->width = w;
	this->height = h;
	if (alloc_map_attr(this) == -1)
		return (-1);
	init_func_ptr(this);
	return (0);
}

int 			destroy_map(Map *this)
{
	free_map_attr(this);
	return (0);
}

static void		init_func_ptr(Map *this)
{
	this->get_width = &get_width;
	this->set_width = &set_width;
	this->get_height = &get_height;
	this->set_height = &set_height;
	this->get_elem = &get_elem;
	this->set_elem = &set_elem;
}

static int 		alloc_map_attr(Map *this)
{
	int 		i;

	if (!(this->map = xmalloc(sizeof(Square *) * (this->height + 1)))) 
		return (-1);
	i = 0;
	while (i < this->height)
		{
			if (!(this->map[i] = xmalloc(sizeof(Square) * (this->width + 1))))
				return (-1);
			++i;
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

static int 		get_width(Map *this)
{
	return (this->width);
}

static void		set_width(Map *this, int w)
{
	this->width = w;
}

static int 		get_height(Map *this)
{
	return (this->height);
}

static void		set_height(Map *this, int h)
{
	this->height = h;
}

static Square	*get_elem(Map *this, int line, int column)
{
	return (&this->map[line][column]);
}

static void		set_elem(Map *this, Square *new_elem, int line, int column)
{
	this->map[line][column] = *new_elem;
}