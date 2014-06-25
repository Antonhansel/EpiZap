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


typedef struct 		Client
{
	int				fd;
	int				nbRequest;
	int				x;
	int				y;
	int				lvl;
	struct Client 	*next;
}					Client;

void		createClient(Client *, int);
int			add_elem(Client **, int);
int			del_elem(Client **, int);
int			get_max_fd(Client *);
void 		init_fd(t_fd *, fd_set *);
void 		check_fd(t_fd **, fd_set *);
void		display_client(Client *);

#endif /* CLIENT_H_ */