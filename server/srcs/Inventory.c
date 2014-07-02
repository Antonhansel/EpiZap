#include "Inventory.h"

static int 		get_object(Inventory *, int);
static void 	set_object(Inventory *, int, int);

int		init_inventory(Inventory *this, pthread_mutex_t *mutex, int mode)
{
	this->nbPlayer = -1;
	if (mode == 0)
	{
		this->tab[LINEMATE] = 0;
		this->tab[DERAUMERE] = 0;
		this->tab[SIBUR] = 0;
		this->tab[MENDIANE] = 0;
		this->tab[PHIRAS] = 0;
		this->tab[THYSTAME] = 0;
		this->tab[FOOD] = 0;
	}
	else
		generate_inventory(this);
	this->mutex = mutex;
	this->get_object = &get_object;
	this->set_object = &set_object;
	return (TRUE);
}

int 	destroy_inventory(Inventory *this)
{
	(void)this;
	return (0);
}

void	generate_inventory(Inventory *this)
{
	this->tab[LINEMATE] = 0;
	this->tab[DERAUMERE] = 0;
	this->tab[SIBUR] = 0;
	this->tab[MENDIANE] = 0;
	this->tab[PHIRAS] = 0;
	this->tab[THYSTAME] = 0;
	this->tab[FOOD] = 0;
	if ((rand() % 2))
	{
		if ((rand() % 3) == 0)
		{
			this->tab[LINEMATE] = rand() % 2;
			this->tab[DERAUMERE] = rand() % 2;
			this->tab[SIBUR] = rand() % 2;
		}
		else
		{
			this->tab[MENDIANE] = rand() % 2;
			this->tab[PHIRAS] = rand() % 2;
			this->tab[THYSTAME] = rand() % 2;
			this->tab[FOOD] = rand() % 2;
		}
	}
}

static int 		get_object(Inventory *this, int type)
{
	return (this->tab[type]);
}

static void		set_object(Inventory *this, int type, int add_val)
{
	this->tab[type] += add_val;
}