/*
** List.h for List.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:17:58 2014 Flavien David
** Last update sam. juil.  12 18:17:58 2014 Flavien David
*/

#ifndef LIST_H_
# define LIST_H_

# include "Server.h"
# include "Network.h"
# include "Player.h"

int	add_elem(t_player **, int);
int	del_elem(t_player **, int);
void	display_list(t_player *);
int	add_player(t_player **, t_player *);
int	add_square(t_player **, t_player *);
int	del_square(t_player **, int);

#endif /* LIST_H_ */
