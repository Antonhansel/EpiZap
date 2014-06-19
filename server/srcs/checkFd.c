/*
** checkFd.c for checkFd.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  jeu. juin  19 12:04:12 2014 jeremie taboada-alvarez
** Last update jeu. juin  19 12:04:12 2014 jeremie taboada-alvarez
*/

#include "checkFd.h"

void 	init_fd(Server *this, fd_set *readfds)
{
	int i;

	i = 0;
	if (this->clients != NULL)
	{
		while (i <= this->maxFd)
		{
			if (this->clients[i] != 0)
			{
				FD_SET(this->clients[i]->fd, readfds);
			}
			i++;
		}
	}
}

void	check_fd(Server *this, fd_set *readfds)
{
	int i;
	int ret;
	char	buff[512];

	i = 0;
	ret = 0;
	memset(buff, 0, 512);
	if (this->clients != NULL)
	{
		while (i <= this->maxFd)
		{
			if (this->clients[i] != NULL && FD_ISSET(this->clients[i]->fd, readfds))
			{
				if ((ret = read(this->clients[i]->fd, buff, 500)) == 0)
				{
					free(this->clients[i]);
					this->clients[i] = NULL;
				}
				else
				{
					printf("--- RECEIVE FROM FD %d ---\n%s", this->clients[i]->fd, buff);
				}
			}				
			i++;
		}
	}
}