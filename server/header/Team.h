#ifndef TEAM_H_
# define TEAM_H_

# include "Player.h"

typedef struct 	s_team
{
	/* data */
	int			nb_player_max;
	int 		nb_player_actu;
	t_player 		*player_list;
	char 		*name;
	/* Method */
	int 		(*get_nb_player_max)(struct s_team *);
	void		(*set_nb_player_max)(struct s_team *, int);
	int 		(*get_nb_player_actu)(struct s_team *);
	void		(*set_nb_player_actu)(struct s_team *, int);
	struct s_team *next;
}				t_team;

int		init_team(t_team *, char *, int);

#endif /* TEAM_H_ */