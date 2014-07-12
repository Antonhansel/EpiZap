/*
** Map.h for Map.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:18:05 2014 Flavien David
** Last update sam. juil.  12 18:18:05 2014 Flavien David
*/

#ifndef MAP_H_
# define MAP_H_

# include "Square.h"

typedef struct	s_map
{
  int		width;
  int		height;
  t_square	**map;
}		t_map;

int		init_map(t_map *, int, int);
int		destroy_map(t_map *);

#endif
