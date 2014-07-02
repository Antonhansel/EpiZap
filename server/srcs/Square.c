#include 	"Square.h"

static Inventory 	*get_inventory(Square *);
static void			set_inventory(Square *, Inventory *);

int 	init_square(Square *this)
{
	if ((this->inventory = malloc(sizeof(Inventory))) == NULL)
		return (1);
	if (init_inventory(this->inventory, NULL, 1) == FALSE)
		return (FALSE);
	this->get_inventory = &get_inventory;
	this->set_inventory = &set_inventory;
	return (0);
}

int 	destroy_square(Square *this)
{
	free(this->inventory);
	return (0);
}

static Inventory 	*get_inventory(Square *this)
{
	return (this->inventory);
}

static void		set_inventory(Square *this, Inventory *i)
{
	this->inventory = i;
}

