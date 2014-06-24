/*
** Client.c for Client.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 16:42:27 2014 jeremie taboada-alvarez
** Last update mer. juin  18 16:42:27 2014 jeremie taboada-alvarez
*/

#include "Client.h"

void		createClient(Client *c, int fd)
{
	c->fd = fd;
	c->nbRequest = 0;
	c->x = 0;
	c->y = 0;
	c->lvl = 1;
}