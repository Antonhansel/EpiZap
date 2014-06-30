#include 	"Player.h"
#include 	"xfunction.h"

static void			init_func_ptr(Player *);
static void			set_inventory(Player *, Inventory *);
static Inventory 	*get_inventory(Player *);

int		init_player(Player *this, int fd)
{
	this->fd = fd;
	this->nb_request = 0;
	this->x = 0;
	this->y = 0;
	this->time = 0;
	this->lvl = 0;
	if (!(this->inventory = xmalloc(sizeof(Inventory))))
		return (-1);
	init_inventory(this->inventory);
	init_func_ptr(this);
	return (0);
}

int 	destroy_player(Player *this)
{
	free(this->inventory);
	return (0);
}

static void		init_func_ptr(Player *this)
{
	this->get_inventory = &get_inventory;
	this->set_inventory = &set_inventory;
	this->fct_read = &fct_read;
}

static void		set_inventory(Player *this, Inventory *i)
{
	this->inventory = i;
}

static Inventory 	*get_inventory(Player *this)
{
	return (this->inventory);
}