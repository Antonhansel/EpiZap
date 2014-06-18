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

void	serverInit(Server *this, int port)
{
	this->port = port;
	printf("--- SERVER INIT ON PORT %d ---\n", this->port);
	this->accept_socket = &accept_socket;
	(*this->accept_socket)(this);
}

static void	accept_socket(Server *s)
{
	printf("--- LISTEN ON PORT %d ---\n", s->port);
}