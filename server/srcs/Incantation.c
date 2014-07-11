#include "Incantation.h"

static t_inventory	*get_lvl(t_incantation *this, int lvl);

void	create_incantation(t_incantation *this)
{
	this->get_lvl = &get_lvl;
}

static t_inventory	*get_lvl(t_incantation *this, int lvl)
{
	return (this->level[lvl]);
}