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
