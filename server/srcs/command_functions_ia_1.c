#include "command_functions.h"
#include "List.h"

void      display_list_square(Player *front_ptr);

int 	up_cmd(Server *s, Player *p, char *cmd)
{
	(void)cmd;
	display_list_square(s->map->map[p->x][p->y].player);
	del_square(&s->map->map[p->x][p->y].player, p->fd);
	display_list_square(s->map->map[p->x][p->y].player);
	(p->dir == NORTH) ? p->y-- : (p->dir == EAST) ? p->x++ : (p->dir == WEST) ?
		p->x-- : p->y++;
	if (p->x >= s->map->width)
		p->x = 0;
	else if (p->x < 0)
		p->x = s->map->width - 1;
	if (p->y >= s->map->height)
		p->y = 0;
	else if (p->y < 0)
		p->y = s->map->height - 1;
	add_square(&s->map->map[p->x][p->y].player, p);
	display_list_square(s->map->map[p->x][p->y].player);
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	return (0);
}

int 	right_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)cmd;
	(p->dir == NORTH) ? (p->dir = EAST) : (p->dir == EAST) ? (p->dir = SOUTH) :
		(p->dir == SOUTH) ? (p->dir = WEST) : (p->dir = NORTH);
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	return (0);
}

int 	left_cmd(Server *s, Player *p, char *cmd)
{
	(void)s;
	(void)cmd;
	(p->dir == NORTH) ? (p->dir = WEST) : (p->dir == WEST) ? (p->dir = SOUTH) :
		(p->dir == SOUTH) ? (p->dir = EAST) : (p->dir = NORTH);
	add_str_in_buffer(&p->buffer_circular, "OK\n");
	p->mode = WRITE;
	return (0);
}

int 	see_cmd(Server *s, Player *p, char *cmd)
{
	(void)cmd;
	(void)s;
	(void)p;
	/*int 	r;
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
			printf("SEE : x : %d && y : %d\n", x, y);
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

int 		inventory_cmd(Server *s, Player *p, char *cmd)
{
	char	str1[256];
	char	str[512];

	(void)s;
	(void)cmd;
	snprintf(str1, 256, "linemate %d, sibur %d, deraumere %d, mendiane %d",
		p->inventory->get_object(p->inventory, LINEMATE),
		p->inventory->get_object(p->inventory, SIBUR),
		p->inventory->get_object(p->inventory, DERAUMERE),
		p->inventory->get_object(p->inventory, MENDIANE));
	snprintf(str, 512, "%s, phiras %d, thystame %d, nourriture %d\n", str1,
		p->inventory->get_object(p->inventory, PHIRAS),
		p->inventory->get_object(p->inventory, THYSTAME),
		p->inventory->get_object(p->inventory, FOOD));
	add_str_in_buffer(&p->buffer_circular, str);
	p->mode = WRITE;
	return (0);
}