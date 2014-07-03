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
	Player 		*(*get_player_list)(struct Team *);
	struct Team *next;
}				Team;

int		init_team(struct Team *, char *, int);
int 	destroy_team(struct Team *);
int 	init_all_teams(void *);

#endif /* TEAM_H_ */