/*
** cmd_functions.h for cmd_functions.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:19:12 2014 Flavien David
** Last update sam. juil.  12 18:19:12 2014 Flavien David
*/

#ifndef CMD_FUNCTIONS_H_
# define CMD_FUNCTIONS_H_

# include "cmd.h"
# include "Server.h"

double	get_min_time(t_cmd *, double);
int	set_new_timer(t_cmd **, t_server *, double);
void	del_cmd_of_player(t_cmd **, t_player *);
void	update_life(t_player **, int);

#endif /* !CMD_FUNCTIONS_H_ */
