#include "Incantation.h"

static Inventory	*get_lvl(Incantation *this, int lvl);

void	create_incantation(Incantation *this)
{
	this->get_lvl = &get_lvl;
}

static Inventory	*get_lvl(Incantation *this, int lvl)
{
	return (this->level[lvl]);
}