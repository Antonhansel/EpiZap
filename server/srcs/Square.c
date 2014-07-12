/*
** Square.c for Square.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:06:17 2014 Flavien David
** Last update sam. juil.  12 18:06:17 2014 Flavien David
*/

#include "Square.h"

static t_inventory	*get_inventory(t_square *);
static void		set_inventory(t_square *, t_inventory *);

int	init_square(t_square *this)
{
  if ((this->inventory = malloc(sizeof(t_inventory))) == NULL)
    return (FALSE);
  if (init_inventory(this->inventory, NULL, 1) == FALSE)
    return (FALSE);
  this->get_inventory = &get_inventory;
  this->set_inventory = &set_inventory;
  this->player = NULL;
  return (TRUE);
}

int	destroy_square(t_square *this)
{
  free(this->inventory);
  return (0);
}

static t_inventory	*get_inventory(t_square *this)
{
  return (this->inventory);
}

static void		set_inventory(t_square *this, t_inventory *i)
{
  this->inventory = i;
}

