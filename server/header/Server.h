#ifndef SERVER_H_
# define SERVER_H_

# include "Network.h"
# include "Player.h"

typedef struct 	Server
{
	/* data */
	int 				port;
	int 				width;
	int 				height;
	int					socket;
	int 				nbPlayer;
	int 				ctime;
	int 				nbPlayerCo;
	int 				maxFd;
	int 				initialize;
	int 				n_client;
	int 				n_malloc;
	char				msg[256];
	struct protoent		*pe;
  	struct sockaddr_in	sin;
  	Client				**clients;
	int					(*accept_socket)(struct Server *);
	void				(*init_fd)(struct Server *, fd_set *);
	void				(*check_fd)(struct Server *, fd_set *);
}				Server;

# ifdef __cplusplus
extern "C" {
# endif
	char 	*server_init(Server *);
	int 	server_loop(Server *);
# ifdef __cplusplus
}
# endif

#endif