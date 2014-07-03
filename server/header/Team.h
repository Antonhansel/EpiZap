#ifndef TEAM_H_
# define TEAM_H_

# include "Player.h"

typedef struct 	Team
{
	/* data */
	int			nb_player_max;
	int 		nb_player_actu;
	Player 		*player_list;
	char 		*name;
	/* Method */
	int 		(*get_nb_player_max)(struct Team *);
	void		(*set_nb_player_max)(struct Team *, int);
	int 		(*get_nb_player_actu)(struct Team *);
	void		(*set_nb_player_actu)(struct Team *, int);
	struct Team *next;
}				Team;

int		init_team(struct Team *, char *, int);

#endif /* TEAM_H_ */