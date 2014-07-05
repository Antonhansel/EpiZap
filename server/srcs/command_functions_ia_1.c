#include "command_functions.h"

int 	up_cmd(Server *s, Player *p)
{
	del_elem(&s->map->map[p->x][p->y].player, p->fd);
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
	add_player(&s->map->map[p->x][p->y].player, p);
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
/*	int 	r;
	int 	c;
	int 	x;
	int 	y;
	char 	str[512];

	r = 0;
	while (r < p->range)
	{
		c = -r;
		while (c <= r)
		{
			x = (p->x + r * di + c * dj + s->map->width) % s->map->width;
			y = (p->y + c * di + r * dj * -1 + s->map->height) % s->map->height;
			//printf("[%.3d]", s->map->map[x][y]);
			c++;
		}
		printf("\n");
		r++;
	}*/
	return (0);
}

/*void    see(int **map, int size, int i, int j, int range, int di, int dj)
{
  
}*/

int 		inventory_cmd(Server *s, Player *p)
{
	char	str1[256];
	char	str[512];

	(void)s;
	snprintf(str1, 256, "linemate %d, sibur %d, deraumere %d, mendiane %d",
		p->inventory->get_object(p->inventory, LINEMATE),
		p->inventory->get_object(p->inventory, SIBUR),
		p->inventory->get_object(p->inventory, DERAUMERE),
		p->inventory->get_object(p->inventory, MENDIANE));
	snprintf(str, 512, "%s, phiras %d, thystame %d, food %d\n", str1,
		p->inventory->get_object(p->inventory, PHIRAS),
		p->inventory->get_object(p->inventory, THYSTAME),
		p->inventory->get_object(p->inventory, FOOD));
	add_str_in_buffer(&p->buffer_circular, str);
	p->mode = WRITE;
	return (0);
}