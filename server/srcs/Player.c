#include "Player.h"

int	init_player(Player *this, int fd)
{
	this->fd = fd;
	this->nbRequest = 0;
	this->x = 0;
	this->y = 0;
	this->time = 0;
	this->lvl = 0;
	this->inventory = malloc(sizeof(Inventory *));
	if (this->inventory == NULL)
		return (1);
	init_inventory(this->inventory);
	return (0);
}