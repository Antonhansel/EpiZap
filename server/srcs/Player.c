#include 	"Player.h"
#include 	"xfunction.h"

static void			set_inventory(Player *, Inventory *);
static Inventory 	*get_inventory(Player *);

int		init_player(Player *this, int fd, int width, int height)
{
	this->fd = fd;
	this->nb_request = 0;
	this->x = rand() % width;
	this->y = rand() % height;
	this->time = 0;
	this->lvl = 0;
	this->mode = WRITE;
	this->intro = TRUE;
	this->buffer_circular = NULL;
	this->get_inventory = &get_inventory;
	this->set_inventory = &set_inventory;
	this->fct_read = &fct_read;
	if (!(this->inventory = xmalloc(sizeof(Inventory))))
		return (-1);
	init_inventory(this->inventory, NULL, 0);
	if (!(this->buffer_circular = xmalloc(sizeof(CircularBuffer))))
		return (-1);
	if (create_circular_buffer(&this->buffer_circular) == FALSE)
		return (-1);
	add_str_in_buffer(&this->buffer_circular, "BIENVENUE\n");
	display_circular_buffer(this->buffer_circular, 1);
	return (0);
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

int 	destroy_player(Player *this)
{
	free(this->inventory);
	//clear_circular_buffer(&this->buffer_circular);
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