/*
** xfunctions.c for xfunctions.c in /home/david_c/B4/unixSystem/my_irc/server/src
** 
** Made by DAVID Flavien
** Login   <david_c@epitech.net>
** 
** Started on  Mon Apr 14 12:10:16 2014 DAVID Flavien
** Last update Fri Apr 18 10:46:18 2014 DAVID Flavien
*/

#include "xfunctions.h"

int	xbind(int sockfd, struct sockaddr_in *addr, socklen_t addrlen)
{
  int	rbind;

  rbind = bind(sockfd, (const struct sockaddr *)addr, addrlen);
  if (rbind == -1)
    {
      perror("Bind ");
      close(sockfd);
      exit(EXIT_FAILURE);
    }
  return (rbind);
}

int	xsocket(int domain, int type, int protocol)
{
  int	fd;

  fd = socket(domain, type, protocol);
  if (fd == -1)
    {
      perror("Socket ");
      exit(EXIT_FAILURE);
    }
  return (fd);
}

int	xaccept(int sockfd, struct sockaddr_in *addr, socklen_t *len)
{
  int	ret;

  ret = accept(sockfd, (struct sockaddr *)addr, len);
  if (ret == -1)
    {
      perror("Accept ");
      close(sockfd);
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xlisten(int sockfd, int backlog)
{
  int	ret;

  ret = listen(sockfd, backlog);
  if (ret == -1)
    {
      perror("Listen ");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int	xconnect(int sockfd, struct sockaddr_in *addr, socklen_t addrlen)
{
  int	ret;

  ret = connect(sockfd, (const struct sockaddr *)addr, addrlen);
  if (ret == -1)
    {
      perror("Connect ");
      exit(EXIT_FAILURE);
    }
  return (ret);
}

int xmalloc(void **obj, int size)
{
  *obj = malloc(size);
  if (*obj == NULL)
  {
    printf("ERROR: [malloc] %p\n", *obj);
    return (-1);
  }
  return (0);
}