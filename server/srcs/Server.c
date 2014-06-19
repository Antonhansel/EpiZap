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
static void 	init_fd(Server *, fd_set *);

void	serverDestroy(Server *this)
{
	this->port = 0;
}

int 	serverInit(Server *this)
{
	int 	opt;

	opt = 1;
	this->maxFd = 3;
	this->clients = NULL;
	printf("--- SERVER INIT ON PORT %d WITH WIDTH OF %d AND HEIGHT OF %d---\n", this->port, this->width, this->height);
	this->accept_socket = &accept_socket;
	this->init_fd = &init_fd;
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

int 				serverLoop(Server *this)
{
	int 			error;
	fd_set 			readfds;
	struct timeval	tv;

	tv.tv_usec = 100;
	tv.tv_sec = 0;
	error = 0;
	while (!error)
	{
		FD_ZERO(&readfds);
		FD_SET(this->socket, &readfds);
		(*this->init_fd)(this, &readfds);
		if (select(this->maxFd + 1, &readfds, NULL, NULL, &tv) == -1)
			return (1);
		else if (FD_ISSET(this->socket, &readfds))
			(*this->accept_socket)(this);			
	}
	return (0);
}

static void 	init_fd(Server *this, fd_set *readfds)
{
	int 		i;

	i = 0;
	if (this->clients != NULL)
	{
		while (i < this->maxFd + 1)
		{
			if (this->clients[i] != NULL)
				FD_SET(this->clients[i]->fd, readfds);
			i++;
		}

	}
}

static void	accept_socket(Server *s)
{
	printf("--- LISTEN ON PORT %d ---\n", s->port);
	int len = sizeof(s->sin);
	int fd = xaccept(s->socket, &(s->sin), (socklen_t *)&len);
	if (s->clients == NULL)
	{
		s->clients = malloc(sizeof(void) * 100);
		s->clients = memset(s->clients, 0, 100);
	}
	Client *c;
	c = malloc(sizeof(Client));
	if (c == NULL)
		exit(1);
	createClient(c, fd);
	s->clients[fd] = c;
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		if (s->clients[i] != NULL)
		{
			printf("--- CLIENT ON FD %d WITH REAL FD %d---\n", i, s->clients[i]->fd);
		}
	}
	printf("--- CLIENT ACCEPT ON FD : %d ---\n", fd);
	write(fd, "--- SUCCESSLY CONNECT ---\n", 26);
/*i = 0;
char buff[512];
int ret = 0;*/
/*while (i < 10)
{
ret = read(s->clients[fd]->fd, buff, 400);
if (ret == 0)
i = 10;
s->clients[fd]->nbRequest++;
printf("--- ADDING REQUEST ON CLIENT WITH FD %d, TOTAL REQUEST %d\n", s->clients[fd]->fd, s->clients[fd]->nbRequest);
i++;
}*/
}