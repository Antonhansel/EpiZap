#ifndef SERVER_H_
# define SERVER_H_

# include "Network.h"
# include "Player.h"
# include "Map.h"
# include "Team.h"
# include "list_team.h"

enum cmd_type
{
	AVANCE,
	DROITE,
	GAUCHE,
	VOIR,
	INVENTAIRE,
	PREND_OBJET,
	POSE_OBJET,
	EXPULSE,
	BROADCAST_TEXTE,
	INCANTATION,
	FORK,
	CONNECT_NBR
};

typedef struct 	Server
{
	/* data */
	int 		port;
	int			socket;
	int 		ctime;
	int 		max_fd;
	int 		nb_player;
	int 		nb_player_co;
	int 		initialize;
	int 		nb_teams;
	int 		nb_player_team;
	char		msg[256];
  	Player		*player;
  	Team 		*team;
  	Map			*map;
  	/* Method */
	int 		(*loop)(struct Server *);
	int			(*accept_socket)(struct Server *);
	void		(*init_fd)(struct Server *, fd_set *);
	void		(*check_fd)(struct Server *, fd_set *);
}				Server;

# ifdef __cplusplus
extern "C" {
# endif
	char 		*init_server(Server *, int, int);
	char		*destroy_server(Server *);
# ifdef __cplusplus
}
# endif

int 	init_bits_fields(Server *, fd_set *, fd_set *);
int 	check_bits_fields(Server *, fd_set *, fd_set *);
int		accept_socket(Server *);
int		fct_write(Player *, void *);

#endif /* SERVER_H_ */