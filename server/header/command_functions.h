/*
** command_functions.h for command_functions.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:19:19 2014 Flavien David
** Last update sam. juil.  12 18:19:19 2014 Flavien David
*/

#ifndef COMMAND_FUNCTIONS_H_
# define COMMAND_FUNCTIONS_H_

# include "Server.h"
# include "Player.h"
# include "List.h"

int	command_functions(void *, t_player *, char *);
int	get_cmd_type(void *, char *);
int	up_cmd(void *, t_player *, char *);
int	right_cmd(void *, t_player *, char *);
int	left_cmd(void *, t_player *, char *);
int	see_cmd(void *, t_player *, char *);
int	inventory_cmd(void *, t_player *, char *);
int	take_object_cmd(void *, t_player *, char *);
int	put_object_cmd(void *, t_player *, char *);
int	kick_cmd(void *, t_player *, char *);
int	broadcast_text_cmd(void *, t_player *, char *);
int	incantation_cmd(void *, t_player *, char *);
int	fork_cmd(void *, t_player *, char *);
int	connect_nbr_cmd(void *, t_player *, char *);
int	get_obj(void *, int, char *);
int	fork_egg(void *, t_player *, char *);
char	*see_next(void *, char *, int, int);
int	see_loop(void *, t_player *, int, int);
int	get_rock(void *, t_player *);
int calc_angle(t_player *, t_player *, void *);
int	search(t_player *, t_player *, void *);

#endif /* COMMAND_FUNCTIONS_H_ */
