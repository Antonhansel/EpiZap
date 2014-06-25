/*
** list.h for list.h in /home/david_c/B4/unixSystem/rendu/PSU_2013_myirc
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Sat Apr 26 23:08:31 2014 DAVID Flavien
** Last update Sat Apr 26 23:08:32 2014 DAVID Flavien
*/

#ifndef __LIST_H_
# define __LIST_H_

# include "Player.h"

int		add_elem(Player **, int);
int		del_elem(Player **, int);
int		check_fd(Player **, fd_set*);
void	init_fd(Player *, fd_set*);
int		get_max_fd(Player *);

#endif /* __LIST_H_ */
