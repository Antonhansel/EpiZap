/*
** Square.h for Square.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:18:37 2014 Flavien David
** Last update sam. juil.  12 18:18:37 2014 Flavien David
*/

#ifndef	SQUARE_H_
# define SQUARE_H_

# include <stdlib.h>
# include <time.h>
# include "Inventory.h"
# include "Player.h"

typedef struct		s_square
{
  int			square_type;
  t_inventory		*inventory;
  t_player		*player;
  t_inventory		*(*get_inventory)(struct s_square *);
  void			(*set_inventory)(struct s_square *,
					 struct s_inventory *);
  t_player		*(*get_player)(struct s_square *);
}			t_square;

int			init_square(t_square *);
int			destroy_square(t_square *);

#endif
