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

char	*checkOption(char **av, char *opt, int ac)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (strncmp(av[i], opt, strlen(opt)) == 0)
			return (((i + 1) < ac) ? av[i + 1] : NULL);
		i++;
	}
	return (NULL);
}

char	*getOptions(Server *s, char **av, int ac)
{
	char	*cc;

	if ((cc = checkOption(av, "-p", ac)) != NULL)
		s->port = getWidth(cc);
	else
		return ("[ERROR]: Missing option -p");
	if ((cc = checkOption(av, "-x", ac)) != NULL)
		s->width = getWidth(cc);
	else
		return ("[ERROR]: Missing option -x");
	if ((cc = checkOption(av, "-y", ac)) != NULL)
		s->height = getWidth(cc);
	else
		return ("[ERROR]: Missing option -y");
	if ((cc = checkOption(av, "-c", ac)) != NULL)
		s->nbPlayer = getWidth(cc);
	else
		return ("[ERROR]: Missing option -c");
	if ((cc = checkOption(av, "-t", ac)) != NULL)
		s->ctime = getWidth(cc);
	else
		return ("[ERROR]: Missing option -t");
	return (NULL);
}

int		main(int ac, char **av)
{
	char	*err;
	Server 	s;

	if (ac > 1)
	{
		if ((err = getOptions(&s, av, ac)) == NULL)
		{
			if (serverInit(&s) == 0)
			{
				(*s.accept_socket)(&s);
				printf("--- MAIN ---\n");
				(*s.accept_socket)(&s);
				serverDestroy(&s);
			}
		}
		else
			printf("%s\n", err);
	}
	return (0);
}