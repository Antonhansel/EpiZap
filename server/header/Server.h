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

typedef struct 	Server
{
	int 		port;
	void		(*accept_socket)(struct Server *);
	/* data */
}				Server;

void	serverInit(Server *, int);
void	serverDestroy(Server *);

#endif /* SERVER_H_ */