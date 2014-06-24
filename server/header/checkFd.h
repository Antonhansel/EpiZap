/*
** checkFd.h for checkFd.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  jeu. juin  19 12:04:06 2014 jeremie taboada-alvarez
** Last update jeu. juin  19 12:04:06 2014 jeremie taboada-alvarez
*/

#ifndef CHECK_FD_
# define CHECK_FD_

# include "Server.h"

void 	init_fd(Server *, fd_set *);
void	check_fd(Server *, fd_set *);

#endif /* CHECK_FD_ */