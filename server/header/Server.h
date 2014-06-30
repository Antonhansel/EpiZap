#ifndef 	SERVER_H_
# define 	SERVER_H_

# include 	"Network.h"
# include 	"Player.h"
# include	"Map.h"

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
	int 		n_client;
	int 		n_malloc;
	char		msg[256];
  	Player		*player;
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
int		accept_socket(Server *);


#endif