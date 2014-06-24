#include "Server.h"
#include "checkFd.h"

static int		accept_socket(Server *);

char 		*serverInit(Server *this)
{
	int 	opt;

	opt = 1;
	this->clients = NULL;
	this->accept_socket = &accept_socket;
	this->init_fd = &init_fd;
	this->check_fd = &check_fd;
	if ((this->pe = getprotobyname("TCP")) == NULL)
		return ("<font color=\"Red\">*** ERROR ON GETPROTOBYNAME ***</font>");
	if ((this->socket = xsocket(AF_INET, SOCK_STREAM, this->pe->p_proto)) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON CREATE SOCKET ***</font>");
	this->sin.sin_family = AF_INET;
	this->sin.sin_port = htons(this->port);
	this->sin.sin_addr.s_addr = INADDR_ANY;
	setsockopt(this->socket, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt));
	if ((xbind(this->socket, &this->sin, sizeof(this->sin))) == FALSE)
		return ("<font color=\"Red\">*** ERROR ON BIND ***</font>");
	xlisten(this->socket, 10);
	this->initialize = TRUE;
	this->maxFd = this->socket;
	return ("<font color=\"Green\">*** SUCCESSLY INIT ***</font>");
}

static int	accept_socket(Server *s)
{
	printf("--- LISTEN ON PORT %d ---\n", s->port);
	int len = sizeof(s->sin);
	int fd = xaccept(s->socket, &(s->sin), (socklen_t *)&len);
	/*if (s->clients == NULL)
	{
		s->clients = malloc(sizeof(void) * 100);
		s->clients = memset(s->clients, 0, 100);
	}
	Client *c;
	if ((c = malloc(sizeof(Client))) == NULL)
		return (-1);
	createClient(c, fd);
	s->clients[fd] = c;*/
	//s->maxFd = fd;
	printf("--- CLIENT ACCEPT ON FD : %d ---\n", fd);
/*	if (write(s->socket, "TT\n", 3) <= 0)
		printf("----> ERROR ON WRITE ---\n");
*/	if (write(fd, "--- SUCCESSLY CONNECT ---\n", 26) <= 0)
		return (1);
	return (0);
}

int 				serverLoop(Server *this)
{
	int 			error;
	int 			result;
	//int 			resultPrev;
	fd_set 			readfds;
	//fd_set 			writefds;
	struct timeval	tv;

	tv.tv_usec = 100;
	tv.tv_sec = 0;
	error = 0;
	result = 0;
	//resultPrev = 0;
	printf("ADDR SERVER : %p && SOCKET FD = %d\n", this, this->socket);
	while (!error)
	{
		FD_ZERO(&readfds);
		FD_SET(this->socket, &readfds);
		//(*this->init_fd)(this, &readfds);
		if ((result = select(this->maxFd + 1, &readfds, NULL, NULL, &tv)) == -1)
			return (1);
		else if (FD_ISSET(this->socket, &readfds))
		{
			printf("SOCKET\n");
			(*this->accept_socket)(this);
			/*int i;
			for (i = 0; i < 10; i++)
			{
				if (this->clients[i] != NULL)
				{
					printf("--- CLIENT ON FD %d WITH REAL FD %d---\n", i, this->clients[i]->fd);
				}
			}*/
		}
		/*else if (result != resultPrev && this->clients != NULL && FD_ISSET(4, &writefds))
		{
			printf("--- CHECK ---\n");
		}*/
		/*else if (result != resultPrev)
		{
			(*this->check_fd)(this, &readfds);
			resultPrev = result;
		}*/
	}
	return (0);
}