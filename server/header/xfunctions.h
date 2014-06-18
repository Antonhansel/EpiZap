/*
** xfunctions.h for xfunctions.h in /home/david_c/B4/unixSystem/rendu/PSU_2013_myirc
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Sat Apr 26 23:07:59 2014 DAVID Flavien
** Last update Sat Apr 26 23:07:59 2014 DAVID Flavien
*/

#ifndef __XFUNCTIONS_H_
# define __XFUNCTIONS_H_

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

int     xconnect(int, struct sockaddr_in *, socklen_t);
int     xlisten(int, int);
int     xaccept(int, struct sockaddr_in *, socklen_t *);
int     xsocket(int, int, int);
int     xbind(int , struct sockaddr_in *, socklen_t);

#endif /* __XFUNCTIONS_H_ */
