#include "command_functions.h"

int 	up_cmd(Server *s, Player *p)
{
	(void)s;
	(p->dir == NORTH) ? p->x++ : (p->dir == EAST) ? p->y++ : (p->dir == WEST) ?
		p->y-- : p->x--;
	if (p->x >= s->map->width)
		p->x = 0;
	else if (p->x < 0)
		p->x = s->map->width;
	if (p->y >= s->map->height)
		p->y = 0;
	else if (p->y < 0)
		p->y = s->map->height;
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	return (0);
}

int 	right_cmd(Server *s, Player *p)
{
	(void)s;
	(p->dir == NORTH) ? (p->dir = EAST) : (p->dir == EAST) ? (p->dir = SOUTH) :
		(p->dir == SOUTH) ? (p->dir = WEST) : (p->dir = NORTH);
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	return (0);
}

int 	left_cmd(Server *s, Player *p)
{
	(void)s;
	(p->dir == NORTH) ? (p->dir = WEST) : (p->dir == WEST) ? (p->dir = SOUTH) :
		(p->dir == SOUTH) ? (p->dir = EAST) : (p->dir = NORTH);
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	return (0);
}

int 	see_cmd(Server *s, Player *p)
{
	(void)s;
	(void)p;
	return (0);
}

int 	inventory_cmd(Server *s, Player *p)
{
	(void)s;
	(void)p;
	return (0);
}