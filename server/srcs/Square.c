#include 			"Square.h"

static void			init_func_ptr(Square *);

static Inventory 	*get_inventory(Square *);
static void			set_inventory(Square *, Inventory *);
static int 			get_square_type(Square *);
static void			set_square_type(Square *, int);

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
	this->get_square_type = &get_square_type;
	this->set_square_type = &set_square_type;
}

static Inventory 	*get_inventory(Square *this)
{
	return (this->inventory);
}

static void			set_inventory(Square *this, Inventory *i)
{
	this->inventory = i;
}

static int 			get_square_type(Square *this)
{
	return (this->square_type);
}

static void			set_square_type(Square *this, int new_val)
{
	this->square_type = new_val;
}

