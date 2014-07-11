#include "Incantation.h"

static t_inventory	*get_lvl(Incantation *this, int lvl);

void	create_incantation(Incantation *this)
{
	this->get_lvl = &get_lvl;
}

static t_inventory	*get_lvl(Incantation *this, int lvl)
{
	return (this->level[lvl]);
}