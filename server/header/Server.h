/*
** Server.h for Server.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 09:40:59 2014 jeremie taboada-alvarez
** Last update mer. juin  18 09:40:59 2014 jeremie taboada-alvarez
*/

#ifndef SERVER_H_
# define SERVER_H_

# include <sys/types.h>
# include <sys/socket.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <netdb.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include "xfunctions.h"
# include "Client.h"

typedef struct 			Server
{
	int 				port;
	int 				width;
	int 				height;
	int					socket;
	int 				nbPlayer;
	int 				ctime;
	int 				nbPlayerCo;
	struct protoent		*pe;
  	struct sockaddr_in	sin;
  	Client				**clients;
	void				(*accept_socket)(struct Server *);
}						Server;

int		serverInit(Server *);
void	serverDestroy(Server *);

#endif /* SERVER_H_ */