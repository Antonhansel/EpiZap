#ifndef SERVER_H_
# define SERVER_H_

# include "Network.h"
# include "Player.h"
# include "Map.h"
# include "Team.h"
# include "list_team.h"
# include "cmd.h"

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

enum obj_type
{
	LINEMATE,
	DERAUMERE,
	SIBUR,
	MENDIANE,
	PHIRAS,
	THYSTAME,
	FOOD
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
	char		msg[BUFFER_SIZE];

  	Player		*player;
  	Team 		*team;
  	Map			*map;

	char		cmd_type[12][15];
	double		time_tab[12];
	char 		obj_type[10][15];
	int 		(*cmd_tab[12])(void *, Player *, char *);

	t_cmd		*cmd_list;
  	
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
	void 		init_all_team(Server *, char *);
# ifdef __cplusplus
}
# endif

int 	init_bits_fields(Server *, fd_set *, fd_set *);
int 	check_bits_fields(Server *, fd_set *, fd_set *);
int		accept_socket(Server *);
int		fct_write(Player *, void *);
void	init_cmd_tab(Server *);
void	init_time_tab(Server *);
void	init_obj_tab(Server *);
void	init_tab_ptr(Server *);


#endif /* SERVER_H_ */