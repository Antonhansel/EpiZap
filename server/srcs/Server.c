/*
** Server.c for Server.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/src
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 09:41:05 2014 jeremie taboada-alvarez
** Last update mer. juin  18 09:41:05 2014 jeremie taboada-alvarez
*/

#include <stdio.h>
#include "Server.h"

static void		accept_socket(Server *);

void	serverDestroy(Server *this)
{
	this->port = 0;
}

int 	serverInit(Server *this)
{
	int 	opt;

	opt = 1;
	this->clients = NULL;
	printf("--- SERVER INIT ON PORT %d WITH WIDTH OF %d AND HEIGHT OF %d---\n", this->port, this->width, this->height);
	this->accept_socket = &accept_socket;
	if ((this->pe = getprotobyname("TCP")) == NULL)
    {
      printf("[ERROR]: error on getprotobyname\n");
      return (1);
    }
	this->socket = xsocket(AF_INET, SOCK_STREAM, this->pe->p_proto);
  	this->sin.sin_family = AF_INET;
  	this->sin.sin_port = htons(this->port);
  	this->sin.sin_addr.s_addr = INADDR_ANY;
  	setsockopt(this->socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
  	xbind(this->socket, &this->sin, sizeof(this->sin));
  	xlisten(this->socket, 10);
 	return (0);
}

static void	accept_socket(Server *s)
{
	printf("--- LISTEN ON PORT %d ---\n", s->port);
  	int len = sizeof(s->sin);
  	int fd = xaccept(s->socket, &(s->sin), (socklen_t *)&len);
  	if (s->clients == NULL)
  	{
	  	s->clients = malloc(sizeof(void) * 100);
		printf("MALLOC\n");  		
  	}
	Client *c;
	c = malloc(sizeof(Client));
	if (c == NULL)
		exit(1);
	printf("BEFORE ADDR OF CLIENT = %p\n", c);
	createClient(c, fd);
	s->clients[fd] = c;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (s->clients[i] != NULL)
		{
			printf("--- CLIENT ON FD %d WITH REAL FD %d---\n", i, s->clients[i]->fd);
			printf("ADDR OF CLIENT = %p\n", s->clients[i]);			
		}
	}
	printf("--- CLIENT ACCEPT ON FD : %d ---\n", fd);
	write(fd, "IT'S WORK AS LIKE AS PENSATO\n", 29);
	i = 0;
	char buff[512];
	while (i < 10)
	{
		read(s->clients[fd]->fd, buff, 400);
		s->clients[fd]->nbRequest++;
		printf("--- ADDING REQUEST ON CLIENT WITH FD %d, TOTAL REQUEST %d\n", s->clients[fd]->fd, s->clients[fd]->nbRequest);
		i++;
	}
}