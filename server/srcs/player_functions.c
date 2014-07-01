#include	"Server.h"
#include	"List.h"

int 		fct_read(Player *this, void *p)
{
	char	buf[512];
	Server	*s;

	s = ((Server *)(p));
	memset(buf, 0, 512);
	if (read(this->fd, buf, 511) > 0)
	{
		sprintf(s->msg, "%s<font color=\"Green\">*** %s ***</font>", (s->msg != NULL) ? s->msg : "", buf);
	}
	else
	{
		sprintf(s->msg, "%s<font color=\"Red\">*** PLAYER %d DISCONNECTED ***</font>", (s->msg != NULL) ? s->msg : "", this->fd);
		printf("----------- AVANT DELETE ----------\n");
		display_list(s->player);
		del_elem(&s->player, s->player->fd);
		printf("----------- APRES DELETE ----------\n");
		display_list(s->player);
		/*if (s->socket > s->max_fd)
			s->max_fd = s->socket;
		else
			s->max_fd = get_max_fd(this);*/
		s->max_fd--;
	}
	return (0);
}