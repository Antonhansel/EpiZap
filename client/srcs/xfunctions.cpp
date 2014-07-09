/*
** xfunctions.c for xfunctions.c in /home/david_c/B4/unixSystem/my_irc/server/src
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Mon Apr 14 12:10:16 2014 DAVID Flavien
** Last update Fri Apr 18 10:46:18 2014 DAVID Flavien
*/

# include <sys/types.h>
# include <stdlib.h>
# include <netdb.h>
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/socket.h>
# include <sys/mman.h>
# include <unistd.h>

bool		xconnect(int sockfd, struct sockaddr_in *addr, socklen_t addrlen)
{
	int	ret;

	ret = connect(sockfd, (const struct sockaddr *)addr, addrlen);
	if (ret == -1)
	{
		return (false);
	}
	return (true);
}