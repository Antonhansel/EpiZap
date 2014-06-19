/*
** Client.h for Client.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 16:42:32 2014 jeremie taboada-alvarez
** Last update mer. juin  18 16:42:32 2014 jeremie taboada-alvarez
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct 	Client
{
	/* data */
	int			fd;
	int			nbRequest;
	int			x;
	int			y;
	int			lvl;
}				Client;

void		createClient(Client *, int);

#endif /* CLIENT_H_ */