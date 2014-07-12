/*
** Inventory.c for Inventory.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:05:32 2014 Flavien David
** Last update sam. juil.  12 18:05:32 2014 Flavien David
*/

#include "Inventory.h"
#include "Server.h"

static int	get_object(t_inventory *, int);
static void	set_object(t_inventory *, int, int);

int	init_inventory(t_inventory *this, pthread_mutex_t *mutex, int mode)
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

int	destroy_inventory(t_inventory *this)
{
  (void)this;
  return (0);
}

void	generate_inventory(t_inventory *this)
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

static int	get_object(t_inventory *this, int type)
{
  return (this->tab[type]);
}

static void	set_object(t_inventory *this, int type, int add_val)
{
  this->tab[type] += add_val;
}
