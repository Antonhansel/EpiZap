/*
** cmd.h for cmd.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:19:04 2014 Flavien David
** Last update sam. juil.  12 18:19:04 2014 Flavien David
*/

#ifndef CMD_H_
# define CMD_H_

# include "Player.h"

typedef struct	s_cmd
{
  char		**cmd;
  int		type;
  double	time;
  t_player	*owner;
  char		*team_name;
  int		num_cmd;
  int		(*func)(void *, t_player *, char *);
  struct s_cmd	*next;
 }		t_cmd;

t_cmd		*create_new_cmd(void *, t_player *, char *);
int		add_cmd_in_list(t_cmd **, t_cmd *);
int		del_cmd_in_list(t_cmd **, t_cmd *);

#endif /* CMD_H_ */
