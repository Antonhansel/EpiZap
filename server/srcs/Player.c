#include "Player.h"
#include "Server.h"
#include "List.h"

static void			set_inventory(Player *, Inventory *);
static Inventory 	*get_inventory(Player *);

int		init_player(Player *this, int fd)
{
	this->fd = fd;
	this->x = -1;
	this->y = -1;
	this->mode = WRITE;
	this->intro = TRUE;
	this->buffer_circular = NULL;
	this->get_inventory = &get_inventory;
	this->set_inventory = &set_inventory;
	this->fct_read = &fct_read;
	this->next_square = NULL;
	this->next_team = NULL;
	this->sent = TRUE;
	this->nb_request = 0;
	this->is_alive = TRUE;
	if (!(this->inventory = malloc(sizeof(Inventory))))
		return (-1);
	init_inventory(this->inventory, NULL, 0);
	if (!(this->buffer_circular = malloc(sizeof(CircularBuffer))))
		return (-1);
	if (create_circular_buffer(&this->buffer_circular) == FALSE)
		return (-1);
	add_str_in_buffer(&this->buffer_circular, "BIENVENUE\n");
	return (0);
}

void	set_player_data(Player *this, int width, int height)
{
	this->nb_request = 0;
	this->x = rand() % width;
	this->y = rand() % height;
	this->dir = rand() % 4;
	this->time = 0;
	this->lvl = 0;
}

void 	copy_player(Player *this, Player *to_copy)
{
	this->fd = to_copy->fd;
	this->lvl = to_copy->lvl;
	this->time = to_copy->time;
	this->x = to_copy->x;
	this->y = to_copy->y;
	this->inventory = to_copy->inventory;
	this->nb_request = to_copy->nb_request;
	this->buffer_circular = to_copy->buffer_circular;
	this->mode = to_copy->mode;
	this->intro = to_copy->intro;
	this->get_inventory = to_copy->get_inventory;
	this->set_inventory = to_copy->set_inventory;
	this->fct_read = to_copy->fct_read;
}

int 		destroy_player(Player *this, void *p)
{
	Server	*s;
	Team	*tmp;

	s = ((Server *)(p));
	tmp = s->team;
	while (tmp)
	{
		if (this->team_name && strcmp(tmp->name, this->team_name) == 0)
		{
			if (del_elem(&tmp->player_list, this->fd) == 0)
				tmp->nb_player_actu--;
		}
		tmp = tmp->next;
	}
	free(this->inventory);
	free(this->team_name);
	return (0);
}

static void		set_inventory(Player *this, Inventory *i)
{
	this->inventory = i;
}

static Inventory 	*get_inventory(Player *this)
{
	return (this->inventory);
}