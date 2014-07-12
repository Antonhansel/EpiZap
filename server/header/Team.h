/*
** Team.h for Team.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:18:52 2014 Flavien David
** Last update sam. juil.  12 18:18:52 2014 Flavien David
*/

#ifndef	TEAM_H_
# define TEAM_H_

# include "Player.h"

typedef struct	s_team
{
  int		nb_player_max;
  int		nb_player_actu;
  t_player	*player_list;
  char		*name;
  int		(*get_nb_player_max)(struct s_team *);
  void		(*set_nb_player_max)(struct s_team *, int);
  int 		(*get_nb_player_actu)(struct s_team *);
  void		(*set_nb_player_actu)(struct s_team *, int);
  struct s_team	*next;
}		t_team;

int		init_team(t_team *, char *, int);

#endif /* !TEAM_H_ */
