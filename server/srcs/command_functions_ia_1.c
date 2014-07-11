#include "command_functions.h"
#include "List.h"

void      display_list_square(t_player *front_ptr);

int 		up_cmd(void *serv, t_player *p, char *cmd)
{
	t_server	*s;

	s = ((t_server*)(serv));
	(void)cmd;
/*printf("----- BEFORE DELETING PLAYER IN SQUARE ----\n");
display_list_square(s->map->map[p->x][p->y].player);
*/	del_square(&s->map->map[p->x][p->y].player, p->fd);
/*	printf("----- BEFORE DELETING PLAYER IN SQUARE ----\n");
display_list_square(s->map->map[p->x][p->y].player);
*/	(p->dir == NORTH) ? p->y-- : (p->dir == EAST) ? p->x++ : (p->dir == WEST) ?
p->x-- : p->y++;
if (p->x >= s->map->width)
	p->x = 0;
else if (p->x < 0)
	p->x = s->map->width - 1;
if (p->y >= s->map->height)
	p->y = 0;
else if (p->y < 0)
	p->y = s->map->height - 1;
/*	printf("----- BEFORE ADDING PLAYER IN SQUARE ----\n");
display_list_square(s->map->map[p->x][p->y].player);
*/	add_square(&s->map->map[p->x][p->y].player, p);
/*	printf("----- AFTER ADDING PLAYER IN SQUARE ----\n");
display_list_square(s->map->map[p->x][p->y].player);
*/	if (p->sent == TRUE)
{
	add_str_in_buffer(&p->buffer_circular, "ok\n");
	p->mode = WRITE;
}
return (0);
}

int 	right_cmd(void *s, t_player *p, char *cmd)
{
	(void)s;
	(void)cmd;
	(p->dir == NORTH) ? (p->dir = WEST) : (p->dir == WEST) ? (p->dir = SOUTH) :
	(p->dir == SOUTH) ? (p->dir = EAST) : (p->dir = NORTH);
	add_str_in_buffer(&p->buffer_circular, "ok\n");
	p->mode = WRITE;
	return (0);
}

int 	left_cmd(void *s, t_player *p, char *cmd)
{
	(void)s;
	(void)cmd;
	(p->dir == NORTH) ? (p->dir = EAST) : (p->dir == EAST) ? (p->dir = SOUTH) :
	(p->dir == SOUTH) ? (p->dir = WEST) : (p->dir = NORTH);
	add_str_in_buffer(&p->buffer_circular, "ok\n");
	p->mode = WRITE;
	return (0);
}

int 		see_cmd(void *s, t_player *p, char *cmd)
{
	int 	di;
	int 	dj;

	di = 0;
	dj = 0;
	(p->dir == NORTH) ? (dj = 1) : (p->dir == SOUTH) ? (dj = -1) :
	(p->dir == WEST) ? (di = -1) : (p->dir == EAST) ? (di = 1) : 0;
	see_loop(s, p, di, dj);
	(void)cmd;
	return (0);
}

int 		inventory_cmd(void *s, t_player *p, char *cmd)
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