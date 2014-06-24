#include "Server.h"

char 		*serverInit(Server *this)
{
	//char	*error;
	int 	opt;

	opt = 1;
	this->maxFd = 3;
	//this->clients = NULL;
	/*if ((error = malloc(sizeof(char) * 512)) == NULL)
		return ("<font color=\"Red\">*** ERROR ON MALLOC ***</font>");*/
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
	return ("<font color=\"Green\">*** SUCCESSLY INIT ***</font>");
}
