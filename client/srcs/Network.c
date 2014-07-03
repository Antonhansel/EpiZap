/*
** xfunctions.c for xfunctions.c in /home/david_c/B4/unixSystem/my_irc/server/src
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Mon Apr 14 12:10:16 2014 DAVID Flavien
** Last update Fri Apr 18 10:46:18 2014 DAVID Flavien
*/

#include "Network.h"

int	xbind(int sockfd, struct sockaddr_in *addr, socklen_t addrlen)
{
	int	rbind;

	rbind = bind(sockfd, (const struct sockaddr *)addr, addrlen);
	if (rbind == -1)
	{
		close(sockfd);
		return (FALSE);
	}
	return (TRUE);
}

int	xsocket(int domain, int type, int protocol)
{
	int	fd;

	fd = socket(domain, type, protocol);
	if (fd == -1)
	{
		return (FALSE);
	}
	return (fd);
}

int	xaccept(int sockfd, struct sockaddr_in *addr, socklen_t *len)
{
	int	ret;

	ret = accept(sockfd, (struct sockaddr *)addr, len);
	if (ret == -1)
	{
		close(sockfd);
		return (FALSE);
	}
	return (ret);
}

int	xlisten(int sockfd, int backlog)
{
	int	ret;

	ret = listen(sockfd, backlog);
	if (ret == -1)
	{
		return (FALSE);
	}
	return (TRUE);
}

int	xconnect(int sockfd, struct sockaddr_in *addr, socklen_t addrlen)
{
	int	ret;

	ret = connect(sockfd, (const struct sockaddr *)addr, addrlen);
	if (ret == -1)
	{
		return (FALSE);
	}
	return (TRUE);
}