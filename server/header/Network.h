/*
** Network.h for Network.h in /home/david_c/B4/systemUnix/psu_2013_zappy/server/header
**
** Made by Flavien David
** Login   <david_c@epitech.net>
**
** Started on  sam. juil.  12 18:18:13 2014 Flavien David
** Last update sam. juil.  12 18:18:13 2014 Flavien David
*/

#ifndef NETWORK_H_
# define NETWORK_H_

# define TRUE	1
# define FALSE	0

# include <unistd.h>
# include <sys/types.h>
# include <stdlib.h>
# include <netdb.h>
# include <stdio.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <string.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <sys/mman.h>

int	xconnect(int, struct sockaddr_in *, socklen_t);
int	xlisten(int, int);
int	xaccept(int, struct sockaddr_in *, socklen_t *);
int	xsocket(int, int, int);
int	xbind(int , struct sockaddr_in *, socklen_t);

#endif
