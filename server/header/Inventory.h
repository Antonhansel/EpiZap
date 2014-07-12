/*
** Inventory.h for Inventory.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:17:52 2014 Flavien David
** Last update sam. juil.  12 18:17:52 2014 Flavien David
*/

#ifndef INVENTORY_H_
# define INVENTORY_H_

# include <pthread.h>
# include <stdlib.h>
# include "string.h"
# include "Network.h"

typedef struct		s_inventory
{
  int			nbPlayer;
  int			tab[10];
  pthread_mutex_t	*mutex;
  int			(*get_object)(struct s_inventory *, int);
  void			(*set_object)(struct s_inventory *, int, int);
}			t_inventory;

int			init_inventory(t_inventory *, pthread_mutex_t *, int);
void			generate_inventory(t_inventory *);

#endif /* !INVENTORY_H_ */
