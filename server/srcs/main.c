/*
** main.c for main.c in /home/david_c/B4/systemUnix/psu_2013_zappy/server/src
**
** Made by jeremie taboada-alvarez
** Login   <david_c@epitech.net>
**
** Started on  mer. juin  18 09:37:04 2014 jeremie taboada-alvarez
** Last update mer. juin  18 09:37:04 2014 jeremie taboada-alvarez
*/

#include "Server.h"
#include "getInfos.h"

char	*checkOption(char **av, char *opt)
{
	int	i;

	i = 0;
	while (av[i] != 0)
	{
		if (strncmp(av[i], opt, strlen(opt)) == 0)
			return (av[i]);
		i++;
	}
	return (NULL);
}

int		main(int ac, char **av)
{
	Server 	s;
	int 	port;
	char	*cc;

	if (ac > 1)
	{
		if ((cc = checkOption(av, "-p")) != NULL)
			port = getPort(cc);
	}
	serverInit(&s, port);
	serverDestroy(&s);
	return (0);
}