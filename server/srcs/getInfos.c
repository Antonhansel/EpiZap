/*
** getInfos.c for getInfos.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/srcs
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 09:57:59 2014 jeremie taboada-alvarez
** Last update mer. juin  18 09:57:59 2014 jeremie taboada-alvarez
*/

#include "getInfos.h"

char		*substr(char *av, int size)
{
	char	*str;

	str = malloc(sizeof(strlen(av)));
	strncat(str, av + size, strlen(av) - size);
	return (str);
}

int			getPort(char *av)
{
	int		port;

	port = atoi(substr(av, 3));
	return (port);
}