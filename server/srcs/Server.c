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
#include "checkFd.h"

static int		accept_socket(Server *);

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
	this->check_fd = &check_fd;
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
	int 			result;
	int 			resultPrev;
	fd_set 			readfds;
	fd_set 			writefds;
	struct timeval	tv;

	tv.tv_usec = 100;
	tv.tv_sec = 0;
	error = 0;
	result = 0;
	resultPrev = 0;
	while (!error)
	{
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);
		FD_SET(this->socket, &readfds);
		FD_SET(this->socket, &writefds);
		(*this->init_fd)(this, &readfds);
		if ((result = select(this->maxFd + 1, &readfds, NULL, NULL, &tv)) == -1)
			return (1);
		else if (FD_ISSET(this->socket, &readfds))
		{
			(*this->accept_socket)(this);
			int i;
			for (i = 0; i < 10; i++)
			{
				if (this->clients[i] != NULL)
				{
					printf("--- CLIENT ON FD %d WITH REAL FD %d---\n", i, this->clients[i]->fd);
				}
			}
		}
		else if (result != resultPrev)
		{
			(*this->check_fd)(this, &readfds);
			resultPrev = result;
		}
	}
	return (0);
}

static int	accept_socket(Server *s)
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
	if (xmalloc((void**)&c, sizeof(Client)) == -1)
		return (-1);
	createClient(c, fd);
	s->clients[fd] = c;
	s->maxFd = fd;
	printf("--- CLIENT ACCEPT ON FD : %d ---\n", fd);
	write(fd, "--- SUCCESSLY CONNECT ---\n", 26);
	return (0);
}