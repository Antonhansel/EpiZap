#include "Inventory.h"


static int 		get_object(Inventory *, int);
static void 	set_object(Inventory *, int, int);

int		init_inventory(Inventory *this)
{
	this->nbPlayer = -1;
	this->tab[LINEMATE] = 0;
	this->tab[DERAUMERE] = 0;
	this->tab[SIBUR] = 0;
	this->tab[MENDIANE] = 0;
	this->tab[PHIRAS] = 0;
	this->tab[THYSTAME] = 0;
	this->tab[FOOD] = 0;
	this->get_object = &get_object;
	this->set_object = &set_object;
	return (0);
}

int 	destroy_inventory(Inventory *this)
{
	(void)this;
	return (0);
}

static int 		get_object(Inventory *this, int type)
{
	return (this->tab[type]);
}

static void		set_object(Inventory *this, int type, int add_val)
{
	this->tab[type] += add_val;
}