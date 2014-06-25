#include "Inventory.h"

static int 	get_object(Inventory *, char *);

void	init_inventory(Inventory *this)
{
	this->get_object = &get_object;
	this->linemate = 0;
	this->deraumere = 0;
	this->sibur = 0;
	this->mendiane = 0;
	this->phiras = 0;
	this->thystame = 0;
	this->food = -1;
	this->nbPlayer = -1;
	this->tab[0] = &this->linemate;
	this->tab[1] = &this->deraumere;
	this->tab[2] = &this->sibur;
	this->tab[3] = &this->mendiane;
	this->tab[4] = &this->phiras;
	this->tab[5] = &this->thystame;
	this->tab[6] = &this->food;
	this->tab[7] = &this->nbPlayer;
	init_inventory_next(this);
}

void	init_inventory_next(Inventory *this)
{
	strcat(this->tab_corresp[0], "linemate");
	strcat(this->tab_corresp[1], "deraumere");
	strcat(this->tab_corresp[2], "sibur");
	strcat(this->tab_corresp[3], "mendiane");
	strcat(this->tab_corresp[4], "phiras");
	strcat(this->tab_corresp[5], "thystame");
	strcat(this->tab_corresp[6], "food");
	strcat(this->tab_corresp[7], "nbPlayer");
}

static int 	get_object(Inventory *this, char *obj)
{
	int 	i;

	i = 0;
	while (this->tab_corresp[i] != 0)
	{
		if (strcmp(this->tab_corresp[i], obj) == 0)
			return (*(this->tab[i]));
		i++;
	}
	return (-1);
}