#include	"Server.h"

int 		fct_read(Player *this, void *p)
{
	char	buf[512];
	Server	*s;

	s = ((Server *)(p));
	if (read(this->fd, buf, 511) > 0)
	{
		sprintf(s->msg, "%s<font color=\"Green\">*** %s ***</font>", (s->msg != NULL) ? s->msg : "", buf);
	}
	else
	{
		sprintf(s->msg, "%s<font color=\"Red\">*** PLAYER %d DISCONNECTED ***</font>", (s->msg != NULL) ? s->msg : "", this->fd);
	}
	return (0);
}