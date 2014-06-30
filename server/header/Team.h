#ifndef 	TEAM_H_
# define 	TEAM_H_

# include 	"Player.h"

typedef struct 	Team
{
	/* data */
	int			nb_player_max;
	int 		nb_player_actu;
	Player 		*player_list;
	/* Method */
	int 		(*get_nb_player_max)(struct Team *);
	void		(*set_nb_player_max)(struct Team *, int);
	int 		(*get_nb_player_actu)(struct Team *);
	void		(*set_nb_player_actu)(struct Team *, int);
	Player 		*(*get_player_list)(struct Team *);
}				Team;

int		init_team(struct Team *, int);
int 	destroy_team(struct Team *);

#endif	/* TEAM_H_ */