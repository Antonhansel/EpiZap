#include 			"Square.h"

static void			init_func_ptr(Square *);

static Inventory 	*get_inventory(Square *);
static void			set_inventory(Square *, Inventory *);

int 				init_square(Square *this, Inventory *i)
{
	this->inventory = i;
	init_func_ptr(this);
	return (0);
}

int 				destroy_square(Square *this)
{
	free(this->inventory);
	return (0);
}

static void			init_func_ptr(Square *this)
{
	this->get_inventory = &get_inventory;
	this->set_inventory = &set_inventory;
}

static Inventory 	*get_inventory(Square *this)
{
	return (this->inventory);
}

static void			set_inventory(Square *this, Inventory *i)
{
	this->inventory = i;
}